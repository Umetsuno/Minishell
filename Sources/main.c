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


void	do_prompt(t_data *data)
{
	while (1)
	{
		init_start_loop(data);
		data->line = readline("\033[4;34mMyBash-2.0$ \033[0m");
		add_history(data->line);
		if (data->line == NULL)
		{
			ft_putstr("\r\033[4;34mMyBash-2.0$ \033[0m");
			data->line = ft_strdup("exit");
		}
		data->line = strtrim_space(data->line);
		if (ft_strlen(data->line) == 0)
			do_prompt(data);
		data->index = 1;
		recover_data(data);
		free(data->line);
		if (data->del_temp == true)
			remove("temp_file");
	}
}

int	main(int ac, char **av, char **env)
{
	init_structure(&g_data, av);
	g_data.env = copy_env(env);
	signal(SIGINT, sig_ctrl_c);
	signal(SIGQUIT, sig_ctrl_bs);
	if (ac != 1)
		return (ft_error_arg("Argument Error: wrong number of arguments.\n"));
	do_prompt(&g_data);
	return (EXIT_SUCCESS);
}
