#include "../../Includes/MiniShell.h"

bool	check_if_have_pipe(t_data *data)
{
	int	i;

	i = 0;
	while (data->all_cmd->argument[i])
	{
		if (!ft_strcmp("|" , data->all_cmd->argument[i]))
		{
			data->check_pipe = true;
			return (true);
		}
		i++;
	}
	return (false);
}

static void	add_to_cmd(t_data *data, int start, int end)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char*) * (end - start + 1));
	tmp[(end - start)] = NULL;
	while (start < end)
	{
		tmp[i] = ft_strdup(data->all_cmd->argument[start]);
		start++;
		i++;
	}
	lstadd_back_cmd(&data->cmd, new_cmd_parsing(tmp));
	free_double_etoile(tmp);
}

void	split_cmd(t_data *data)
{
	int	start;
	int	i;

	i = 0;
	start = 0;
	while (data->all_cmd->argument[i])
	{
		if (!ft_strcmp("|" , data->all_cmd->argument[i]))
		{
			add_to_cmd(data, start, i);
			i++;
			start = i;
		}
		i++;
	}
	add_to_cmd(data, start, i);
	set_up_prev(data);
}
