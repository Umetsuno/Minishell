#include "../../Includes/MiniShell.h"

// int	init_pipe(t_data *data)
// {
// 	if (!data->cmd->prev)
// 	{
// 		dup2(data->cmd->pipefd[1], 1);
// 		close(data->cmd->pipefd[0]);
// 	}
// 	else if (data->cmd->prev && data->cmd->next)
// 	{
// 		dup2(data->cmd->prev->pipefd[0], 0);
// 		dup2(data->cmd->pipefd[1], 1);
// 	}
// 	else
// 	{
// 		dup2(data->cmd->prev->pipefd[0], 0);
// 		replace_fd(data);
// 	}
// 	return (0);
// }

void	child(t_data *data)
{
	exe_cmd(data);
	exit(EXIT_SUCCESS);
}
