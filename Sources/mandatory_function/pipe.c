/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:13:25 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/31 14:13:27 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	close_all_pid(t_data *data)
{
	t_cmd	*cursor;

	cursor = data->save_cmd;
	while (cursor)
	{
		waitpid(cursor->pid, &cursor->status, 0);
		cursor = cursor->next;
	}
}

void	close_pipe(t_data *data)
{
	if (!data->cmd->prev)
		close(data->cmd->pipefd[1]);
	else if (data->cmd->prev && data->cmd->next)
	{
		close(data->cmd->prev->pipefd[0]);
		close(data->cmd->pipefd[1]);
	}
	else if (data->cmd->prev && !data->cmd->next)
	{
		close(data->cmd->pipefd[0]);
		close(data->cmd->pipefd[1]);
	}
}

static void	init_pipe(t_data *data)
{
	if (!data->cmd->prev)
	{
		dup2(data->cmd->pipefd[1], 1);
		close(data->cmd->pipefd[0]);
	}
	else if (data->cmd->prev && data->cmd->next)
	{
		dup2(data->cmd->prev->pipefd[0], 0);
		dup2(data->cmd->pipefd[1], 1);
		close(data->cmd->pipefd[0]);
		close(data->cmd->pipefd[1]);
	}
	else if (data->cmd->prev && !data->cmd->next)
	{
		dup2(data->cmd->prev->pipefd[0], 0);
		close(data->cmd->pipefd[0]);
		close(data->cmd->pipefd[1]);
		replace_fd(data);
	}
}

void	child(t_data *data)
{
	init_pipe(data);
	exe_cmd(data);
	exit(EXIT_SUCCESS);
}
