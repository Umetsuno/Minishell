/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faherrau <faherrau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:12:43 by faherrau          #+#    #+#             */
/*   Updated: 2021/06/28 13:52:41 by faherrau         ###   ########lyon.fr   */
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

void	recover_data(t_data *data)
{
	/* parsing fab */
	// parser(data);
	/* temporaire */data->parsing.argument = ft_split(data->line, ' ');
	/* temporaire */data->parsing.cmd = data->parsing.argument[0];
	/* parsing fab */
	int code;

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
}

int	ft_error_arg(char *str)
{
	write(1, &str, ft_strlen(str));
	return (1);
}

void	sig_ctrl_c(int signal)
{
	(void)signal;
}

void	sig_ctrl_bs(int signal)
{
	printf("coucou \\");
	ft_putstr("MiniShell ");
	(void)signal;
}

void	do_prompt(t_data *data)
{
	while (1)
	{
		data->fd = 1;
		build_pwd(data);
		data->line = readline("MiniShell ");
		add_history(data->line);
		if (data->line == NULL)
		{
			ft_putstr("\rMiniShell ");
			data->line = ft_strdup("exit");
		}
		data->line = strtrim_space(data->line);
		if (ft_strlen(data->line) == 0)
			do_prompt(data);
		/**/
		recover_data(data);
		free(data->line);
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
