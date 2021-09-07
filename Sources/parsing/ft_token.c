/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oghma <fabien@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:11:40 by oghma             #+#    #+#             */
/*   Updated: 2021/09/03 18:17:17 by oghma            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

static int	quote_sizing(t_data *data)
{
	data->index++;
	while (data->line[data->index])
	{
		if (data->line[data->index] == data->parseur.type_cote)
			return (data->index);
		data->index++;
	}
	return (-1);
}

static int	copy_in_to_string(t_data *data, int end, int *start, int i)
{
	while (*start < end && data->line[*start] != data->parseur.type_cote)
	{
		if (data->line[*start] != data->parseur.type_cote)
		{
			data->parseur.token[i] = data->line[*start];
			i++;
		}
		*start += 1;
	}
	return (i);
}

static void	alt_string(t_data *data, int end, int start)
{
	int	i;

	i = 0;
	data->parseur.token = NULL;
	data->parseur.token = ft_calloc(((end - start) + 1), sizeof(char));
	while (start < end)
	{
		if (data->line[start] == 34 || data->line[start] == 39)
		{
			data->parseur.type_cote = data->line[start++];
			i = copy_in_to_string(data, end, &start, i);
		}
		if (data->line[start] != data->parseur.type_cote)
		{
			data->parseur.token[i] = data->line[start];
			i++;
		}
		start++;
	}
	data->parseur.token[i] = '\0';
}

int	ft_token(t_data *data)
{
	data->parseur.start = data->index;
	data->parseur.type_cote = 1;
	while (data->line[data->index] && data->line[data->index] != ' ')
	{
		if ((data->line[data->index] == 34) || (data->line[data->index] == 39))
		{
			data->parseur.type_cote = data->line[data->index];
			data->index = quote_sizing(data);
			if (data->index == -1)
				return (data->index);
		}
		data->index++;
	}
	alt_string(data, data->index, data->parseur.start);
	return (SUCCESS);
}
