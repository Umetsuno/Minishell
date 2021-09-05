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

static int	quote_sizing(char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (str[i] == str[0])
			return (i);
		i++;
	}
	return (-1);
}


static char	*alt_string(t_data *data, int end, int start)
{
	char	*token;
	int		i;

	i = 0;
	token = NULL;
	token = ft_calloc(((end - start) + 1), sizeof(char));
	while (start < end)
	{
		if (data->line[start] != data->parseur.type_cote)
		{
			token[i] = data->line[start];
			i++;
		}
		start++;
	}
	token[i] = '\0';
	return (token);
}

int	ft_token(t_data *data)
{
	int	i;

	i = data->index;
	data->parseur.start = i;
	data->parseur.type_cote = 0;
	while (data->line[i] && data->line[i] != ' ')
	{
		if ((data->line[i] == 34) || (data->line[i] == 39))
		{
			printf("befor quote index = %d - char = '%c'\n", i , data->line[i]);
			data->parseur.type_cote = data->line[i];
			i = quote_sizing(&data->line[i]);
			printf("afther quote index = %d - char = '%c'\n", i , data->line[i]);
			if (i == -1)
				return (i);
		}
		i++;
	}
	data->parseur.token = alt_string(data, i, data->index);
	data->index = i;
	return (SUCCESS);
}
