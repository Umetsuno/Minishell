/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:12:43 by faherrau          #+#    #+#             */
/*   Updated: 2021/06/29 17:45:39 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/MiniShell.h"

int		is_builting_cmd(t_data *data)
{
	if (ft_strcmp("exit", data->parsing.cmd) == SUCCESS)
		return (FCT_EXIT);
	else if (ft_strcmp("pwd", data->parsing.cmd) == SUCCESS)
		return (FCT_PWD);
	else if (ft_strcmp("env", data->parsing.cmd) == SUCCESS)
		return (FCT_ENV);
	else if (ft_strcmp("cd", data->parsing.cmd) == SUCCESS)
		return (FCT_CD);
	else if (ft_strcmp("unset", data->parsing.cmd) == SUCCESS)
		return (FCT_UNSET);
	else if (ft_strcmp("echo", data->parsing.cmd) == SUCCESS)
		return (FCT_ECHO);
	else if (ft_strcmp("export", data->parsing.cmd) == SUCCESS)
		return (FCT_EXPORT);
	else
		return (NO_FCT);
}

void	split_cmd(t_data *data)
{
	(void)data;
}

void	recover_data(t_data *data)
{
	/* parsing fab */
	// parser(data);
	/* temporaire */data->parsing.argument = ft_split(data->line, ' ');
	/* temporaire */data->parsing.cmd = ft_strdup(data->parsing.argument[0]);
	/* parsing fab */
	int code;
	t_data	*data2;

	data2 = malloc(sizeof(t_data*));
	data2 = data;

	data2->parsing.argument = ft_split("echo bien et toi", ' ');
	data2->parsing.cmd = ft_strdup(data2->parsing.argument[0]);
	if (data->pipe != 0)
		split_cmd(data);

	data->in_cmd = true;
	if (scan_input(data))
		return ;
	scan_fd(data);
	/* a lancer la fonction scan_fd que si il n'y a pas derreur d'arg comme > ou >> puis rien.
	Print le msg d'erreur suivant si le cas au dessus arrive :
	bash: syntax error near unexpected token `newline' errno = 258;
	*/
	code = is_builting_cmd(data);
	if (code != NO_FCT)
		ft_exec_builting_cmd(data, code);
	else if (get_path(data) == SUCCESS)
		ft_exec_path(data);
	else
	{
		printf("bash: %s: command not found\n", data->line);
		errno = 127;
	}
	free(data->parsing.cmd);
	free_double_etoile(data->parsing.argument);
}

int	ft_error_arg(char *str)
{
	write(1, &str, ft_strlen(str));
	return (1);
}

void	sig_ctrl_c(int signal)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)signal;
}

void	sig_ctrl_bs(int signal)
{
	if (g_data[0].in_cmd == true)
		printf("Quit: 3\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)signal;
}

void	do_prompt(t_data **data)
{
	while (1)
	{
		init_start_loop(data[0]);
		init_start_loop(data[1]);
		data[0]->line = readline("\033[4;34mMyBash-2.0$ \033[0m");
		add_history(data[0]->line);
		if (data[0]->line == NULL)
		{
			ft_putstr("\r\033[4;34mMyBash-2.0$ \033[0m");
			data[0]->line = ft_strdup("exit");
		}
		data[0]->line = strtrim_space(data[0]->line);
		if (ft_strlen(data[0]->line) == 0)
			do_prompt(data);
		data[0]->index = 1;
		recover_data(data);
		free(data[0]->line);
		if (data[0]->del_temp == true)
			remove("temp_file");
	}
}

int	main(int ac, char **av, char **env)
{
	g_data = malloc(sizeof(t_data*) * 2);
	init_structure(&g_data[0], av);
	init_structure(&g_data[1], av);
	g_data[0].env = copy_env(env);
	g_data[1].env = copy_env(env);
	signal(SIGINT, sig_ctrl_c);
	signal(SIGQUIT, sig_ctrl_bs);
	if (ac != 1)
		return (ft_error_arg("Argument Error: wrong number of arguments.\n"));
	do_prompt(&g_data);
	return (EXIT_SUCCESS);
}
