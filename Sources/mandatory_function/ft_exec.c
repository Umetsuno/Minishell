/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:09:27 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/23 15:15:57 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	ft_exec_path(t_data *data)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = 0;
	pid = fork();
	if (pid == -1)
		printf("Error (fork) : %s\n", strerror(errno));
	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
	{
		if (execve(data->cmd->cmd, data->cmd->argument, data->env) == -1)
				printf("Error (execve) : %s\n", strerror(errno));
		else
			errno = 0;
	}
}

void	ft_exec_builting_cmd(t_data *data, int code)
{
	if (FCT_EXIT == code)
		data->f[FCT_EXIT](data);
	else if (FCT_PWD == code)
		data->f[FCT_PWD](data);
	else if (FCT_ENV == code)
		data->f[FCT_ENV](data);
	else if (FCT_CD == code)
		data->f[FCT_CD](data);
	else if (FCT_UNSET == code)
		data->f[FCT_UNSET](data);
	else if (FCT_ECHO == code)
		data->f[FCT_ECHO](data);
	else if (FCT_EXPORT == code)
		data->f[FCT_EXPORT](data);
}
