#include "../../Includes/MiniShell.h"

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
