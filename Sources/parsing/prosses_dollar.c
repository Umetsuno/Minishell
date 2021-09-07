/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prosses_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:13:19 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/31 14:15:27 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

static char	*get_name_var(t_data *data, int *i)
{
	int		save;
	int		y;
	char	*name;

	y = 0;
	*i += 1;
	save = *i;
	while (data->line && data->line[*i] != ' ' && data->line[*i] != data->parseur.type_cote)
		*i += 1;
	name = ft_calloc((*i - save) + 2, sizeof(char));
	while (save < *i)
	{
		name[y] = data->line[save];
		y++;
		save++;
	}
	name[y++] = '=';
	name[y] = 0;
	return (name);
}

int	prosses_dollar(t_data *data, int *start, int *i)
{
	char	*name;
	char	*var;
	int		y;

	y = 0;
	var = NULL;
	name = get_name_var(data, start);
	var = my_getenv(data, name);
	if (!var)
		return (-1);
	while (var[y])
	{
		data->parseur.token[*i] = var[y];
		*i += 1;
		y++;
	}
	free(var);
	free(name);
	return (SUCCESS);
}