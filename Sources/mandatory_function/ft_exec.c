/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:09:27 by sbaranes          #+#    #+#             */
/*   Updated: 2021/05/25 22:31:11 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	ft_exec_path(t_data *data)
{
	// data->parsing.argument = malloc(sizeof(char *) * 2);
	// data->parsing.argument[0] = "ls";
	// data->parsing.argument[1] = NULL;
	pid_t	pid;
	int		status;

	status = 0;
	pid = 0;
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (execve(data->parsing.cmd, data->parsing.argument, data->env) == -1)
			printf("Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void	ft_exec_builting_cmd(t_data *data)
{
	if (ft_strcmp("exit", data->line) == SUCCESS)
		data->f[FCT_EXIT](data);
	else if (ft_strcmp("pwd", data->line) == SUCCESS)
		data->f[FCT_PWD](data);
	else if (ft_strcmp("env", data->line) == SUCCESS)
		data->f[FCT_ENV](data);
}
