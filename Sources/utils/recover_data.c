#include "../../Includes/MiniShell.h"

void	cmd_check_cmd(t_data *data)
{
	if (check_if_have_cmd(data) == true)
		cmd_split_cmd(data);
	else
		data->all_cmd = new_cmd_parsing(data->parseur.argument);
	free_double_etoile(data->parseur.argument);
}

void	check_pipe(t_data *data)
{
	if (check_if_have_pipe(data) == true)
		split_cmd(data);
	else
		data->cmd = new_cmd_parsing(data->all_cmd->argument);
}

void	recover_data(t_data *data)
{
	/* parsing fab */
	// parser(data);
	/* temporaire */ data->parseur.argument = ft_split(data->line, ' ');
	/* parsing fab */

	cmd_check_cmd(data);
	data->save_all_cmd = data->all_cmd;
	while (data->all_cmd)
	{
		check_pipe(data);
		data->save_cmd = data->cmd;
		if (data->check_pipe == false)
			exe_cmd(data);
		else
			exe_pipe(data);
		cmdclear(data);
		data->all_cmd = data->all_cmd->next;
	}
	big_cmdclear(data);
}
