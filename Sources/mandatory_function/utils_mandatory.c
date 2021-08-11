#include "../../Includes/MiniShell.h"

void	exe_cmd(t_data *data)
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

void	exe_pipe(t_data *data)
{
	(void)data;
}

int		is_builting_cmd(t_data *data)
{
	if (ft_strcmp("exit", data->parsing->cmd) == SUCCESS)
		return (FCT_EXIT);
	else if (ft_strcmp("pwd", data->parsing->cmd) == SUCCESS)
		return (FCT_PWD);
	else if (ft_strcmp("env", data->parsing->cmd) == SUCCESS)
		return (FCT_ENV);
	else if (ft_strcmp("cd", data->parsing->cmd) == SUCCESS)
		return (FCT_CD);
	else if (ft_strcmp("unset", data->parsing->cmd) == SUCCESS)
		return (FCT_UNSET);
	else if (ft_strcmp("echo", data->parsing->cmd) == SUCCESS)
		return (FCT_ECHO);
	else if (ft_strcmp("export", data->parsing->cmd) == SUCCESS)
		return (FCT_EXPORT);
	else
		return (NO_FCT);
}
