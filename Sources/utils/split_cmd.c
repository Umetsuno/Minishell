/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oghma <fabien@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:06:25 by sbaranes          #+#    #+#             */
/*   Updated: 2021/09/03 18:17:05 by oghma            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

bool	check_if_have_cmd(t_data *data)
{
	int	i;

	i = 0;
	while (data->parseur.argument[i])
	{
		if (!ft_strcmp(";", data->parseur.argument[i]))
			return (true);
		i++;
	}
	return (false);
}

static void	add_cmd_to_cmd(t_data *data, int start, int end)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_calloc((end - start + 1), sizeof(char *));
	tmp[(end - start)] = NULL;
	while (start < end)
	{
		tmp[i] = ft_strdup(data->parseur.argument[start]);
		start++;
		i++;
	}
	lstadd_back_cmd(&data->all_cmd, new_cmd_parsing(tmp));
	free_double_etoile(tmp);
}

void	cmd_split_cmd(t_data *data)
{
	int	start;
	int	i;

	i = 0;
	start = 0;
	while (data->parseur.argument[i])
	{
		if (!ft_strcmp(";", data->parseur.argument[i]))
		{
			add_cmd_to_cmd(data, start, i);
			i++;
			start = i;
		}
		i++;
	}
	add_cmd_to_cmd(data, start, i);
}
