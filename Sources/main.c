/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:12:43 by faherrau          #+#    #+#             */
/*   Updated: 2021/06/14 21:15:27 by sbaranes         ###   ########lyon.fr   */
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
	data->parsing.argument = ft_split(data->line, ' ');
	data->parsing.cmd = data->parsing.argument[0];
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
	printf("\ntest ctrl_c %d\n", signal);
	do_prompt(&g_data);
}

void	sig_catch(int signal)
{
	if (signal == SIGINT)
		printf("\ntest ctrl_c %d\n", signal);
	else if (signal == SIGQUIT)
		printf("\ntest ctrl_\\ %d\n", signal);
	if (g_data.line)
		free(g_data.line);
	do_prompt(&g_data);
	(void)signal;
}

void	do_prompt(t_data *data)
{
	while (1)
	{
		build_pwd(data);
		data->line = readline("\033[3;34mprompt : \033[0m");
		if (data->line == NULL)
		{
			ft_putstr("\r\033[3;34mprompt : \033[0m");
			data->line = ft_strdup("exit");
		}
		data->line = strtrim_space(data->line);
		if (ft_strlen(data->line) == 0)
			do_prompt(data);
		recover_data(data);
		free(data->line);
	}
}

int	main(int ac, char **av, char **env)
{
	init_structure(&g_data, av);
	copy_env(&g_data, env);
	signal(SIGINT, sig_ctrl_c);
	signal(SIGQUIT, sig_catch);
	if (ac != 1)
		return (ft_error_arg("Argument Error: wrong number of arguments.\n"));
	do_prompt(&g_data);
	return (EXIT_SUCCESS);
}
