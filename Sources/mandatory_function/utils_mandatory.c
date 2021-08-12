#include "../../Includes/MiniShell.h"

void	test(t_data *data)
{
	int code;

	data->in_cmd = true;
	if (scan_input(data))
		return ;
	scan_fd(data);
	/* a lancer la fonction scan_fd que si il n'y a pas derreur d'arg comme > ou >> puis rien.
	Print le msg d'erreur suivant si le cas au dessus arrive :
	bash: syntax error near unexpected token `newline' errno = 258;
	*/
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

void	exe_cmd(t_data *data)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = 0;
	pid = fork();

	if (pid == -1)
		printf("Error (fork) : %s\n", strerror(errno));
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		test(data);
		errno = 0;
		exit(EXIT_FAILURE);
	}

}

void	exe_pipe(t_data *data)
{
	int	status;

	while (data->cmd)
	{
		status = 0;
		// if (!init_pipe(data))
		// 	return ;
		data->cmd->pid = fork();
		if (data->cmd->pid == -1)
			return (ft_strerror(data->cmd->cmd, NULL, strerror(errno)));
		else if (data->cmd->pid > 0)
		{
			waitpid(data->cmd->pid, &status, 0);
			kill(data->cmd->pid, SIGTERM);
			if (data->cmd->prev != NULL)
				close(data->cmd->prev->pipefd[0]);
			if (data->cmd->pipefd[1] != 0)
				close(data->cmd->pipefd[1]);
			data->cmd = data->cmd->next;
		}
		else
		{
			child(data);
		}
	}
}

int		is_builting_cmd(t_data *data)
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
