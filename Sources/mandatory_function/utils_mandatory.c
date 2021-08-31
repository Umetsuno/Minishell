/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mandatory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:13:19 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/31 14:15:27 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

/* a lancer la fonction scan_fd que si il n'y a pas derreur d'arg comme :
** > ou >> puis rien.
** Print le msg d'erreur suivant si le cas au dessus arrive :
** bash: syntax error near unexpected token `newline' errno = 258;
*/

void	exe_cmd(t_data *data)
{
	int	code;

	data->in_cmd = true;
	if (scan_input(data))
		return ;
	scan_fd(data);
	code = is_builting_cmd(data);
	if (code != NO_FCT)
		ft_exec_builting_cmd(data, code);
	else if (get_path(data) == SUCCESS)
		ft_exec_path(data);
	else
	{
		ft_strerror(data->cmd->argument[0], NULL, "command not found\n");
		errno = 127;
	}
	data->my_errno = errno;
}

void	exe_pipe(t_data *data)
{
	while (data->cmd)
	{
		if (pipe(data->cmd->pipefd) == -1)
			return ;
		data->cmd->pid = fork();
		if (data->cmd->pid == -1)
			return (ft_strerror(data->cmd->cmd, NULL, strerror(errno)));
		else if (data->cmd->pid > 0)
		{
			close_pipe(data);
			data->cmd = data->cmd->next;
		}
		else
			child(data);
	}
	close_all_pid(data);
}

int	is_builting_cmd(t_data *data)
{
	if (ft_strcmp("exit", data->cmd->cmd) == SUCCESS)
		return (FCT_EXIT);
	else if (ft_strcmp("pwd", data->cmd->cmd) == SUCCESS)
		return (FCT_PWD);
	else if (ft_strcmp("env", data->cmd->cmd) == SUCCESS)
		return (FCT_ENV);
	else if (ft_strcmp("cd", data->cmd->cmd) == SUCCESS)
		return (FCT_CD);
	else if (ft_strcmp("unset", data->cmd->cmd) == SUCCESS)
		return (FCT_UNSET);
	else if (ft_strcmp("echo", data->cmd->cmd) == SUCCESS)
		return (FCT_ECHO);
	else if (ft_strcmp("export", data->cmd->cmd) == SUCCESS)
		return (FCT_EXPORT);
	else
		return (NO_FCT);
}
