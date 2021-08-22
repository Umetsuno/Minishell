#include "../../Includes/MiniShell.h"

void	close_all_pid(t_data *data)
{
	t_cmd	*cursor;

	cursor = data->save_cmd;
	while (cursor)
	{
		waitpid(cursor->pid, &cursor->status, 0);
		kill(cursor->pid, SIGKILL);
		cursor = cursor->next;
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
