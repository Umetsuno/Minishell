#include "../../Includes/MiniShell.h"

void	close_all_pid(t_data *data)
{
	t_cmd	*cursor;

	cursor = data->save_cmd;
	// puts("here");
	// while (cursor)
	// {
	// 	waitpid(data->cmd->pid, &data->cmd->status, 0);
	// 	kill(data->cmd->pid, SIGTERM);
	// 	cursor = cursor->next;
	// }
	// puts("here 2");
}

static void	init_pipe(t_data *data)
{
	if (!data->cmd->prev)
	{
		puts("pipe 1");
		dup2(data->cmd->pipefd[1], 1);
		close(data->cmd->pipefd[0]);
	}
	else if (data->cmd->prev && data->cmd->next)
	{
		puts("pipe 2");
		dup2(data->cmd->prev->pipefd[0], 0);
		dup2(data->cmd->pipefd[1], 1);
		close(data->cmd->pipefd[0]);
	}
	else if (data->cmd->prev && !data->cmd->next)
	{
		puts("pipe 3");
		dup2(data->cmd->prev->pipefd[0], 0);
		close(data->cmd->pipefd[0]);
		replace_fd(data);
	}
}

void	child(t_data *data)
{
	init_pipe(data);
	exe_cmd(data);
	exit(EXIT_SUCCESS);
}
