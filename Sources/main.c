/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:12:43 by faherrau          #+#    #+#             */
/*   Updated: 2021/06/08 14:48:33 by sbaranes         ###   ########lyon.fr   */
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
	if (get_path(data) == SUCCESS)
		ft_exec_path(data);
	else if (code != NO_FCT)
		ft_exec_builting_cmd(data, code);
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

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		ret;

	init_structure(&data, av, env);
	if (ac != 1)
		return (ft_error_arg("Argument Error: wrong number of arguments.\n"));
	while (1)
	{
		build_pwd(&data);
		dprintf(1, "\033[3;34mprompt : \033[0m");
		ret = get_next_line(1, &data.line);
		if (ret == -1)
			return (EXIT_FAILURE);
		data.line = strtrim_space(data.line);
		recover_data(&data);
		free(data.line);
	}
	return (EXIT_SUCCESS);
}
