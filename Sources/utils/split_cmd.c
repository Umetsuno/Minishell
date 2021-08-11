#include "../../Includes/MiniShell.h"

bool	check_if_have_pipe(t_data *data)
{
	int	i;

	i = 0;
	while (data->parseur.argument[i])
	{
		if (!ft_strcmp("|" , data->parseur.argument[i]))
			return (true);
		i++;
	}
	return (false);
}

static void	add_to_cmd(t_data *data, int start, int end)
{
	char	**tmp;

	tmp = malloc(sizeof(char*) * (start + end + 1));
	while (start < end)
	{
		printf("");
		tmp[start] = ft_strdup(data->parseur.argument[start]);
		start++;
	}
	lstadd_back_cmd(&data->all_cmd, new_cmd_parsing(tmp));
}

void	split_cmd(t_data *data)
{
	int	start;
	int	i;

	i = 0;
	start = 0;
	while (data->parseur.argument[i])
	{
		if (!ft_strcmp("|" , data->parseur.argument[i]) || !data->parseur.argument[i + 1])
		{
			printf("start = %d | end = %d", start , i);
			add_to_cmd(data, start, i);
			start = i;
		}
		i++;
	}
	free_double_etoile(data->parseur.argument);
}
