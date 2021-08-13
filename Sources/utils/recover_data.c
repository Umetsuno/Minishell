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
		data->cmd_unique = new_cmd_parsing(data->all_cmd->argument);
}

void	recover_data(t_data *data)
{
	/* parsing fab */
	// parser(data);
	/* temporaire */ data->parseur.argument = ft_split(data->line, ' ');
	/* parsing fab */

	cmd_check_cmd(data);
	puts("start test");
	t_cmd *t;
	t = data->all_cmd;
	int y = 0;
	int i;
	while (t)
	{
		printf("\ncmd %d = :\n\n", y);
		i = 0;
		while (t->argument[i])
		{
			printf("arg %d = '%s'\n", i, t->argument[i]);
			i++;
		}
		y++;
		t = t->next;
	}
	puts("\nend test");
	while (data->all_cmd)
	{
		check_pipe(data);
		data->cmd_unique = data->all_cmd;
		data->cmd = data->cmd_unique;
		if (data->check_pipe == false)
			exe_cmd(data);
		else
			exe_pipe(data);
		cmdclear(data);
		data->all_cmd = data->all_cmd->next;
	}
	big_cmdclear(data);
}
