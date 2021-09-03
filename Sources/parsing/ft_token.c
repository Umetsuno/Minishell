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

static char	*alt_string(t_data *data, char *token, int end)
{
	int i;

	i = 0;
	if (data->parseur.check == true)
	{
		data->parseur.start++;
		end--;
	}
	token = (char *)malloc(sizeof(char) * ((end - data->parseur.start) + 1));
	while (data->parseur.start < end)
	{
		token[i] = data->line[data->parseur.start];
		i++;
		data->parseur.start++;
	}
	token[i] = '\0';
	return (token);
}

int	ft_token(t_data *data, char *token)
{
	int		i;

	i = data->index;
	data->parseur.start = i;
	data->parseur.check = false;
	while (data->line[i] && data->line[i] != ' ')
	{
		if ((data->line[i] == 34) || (data->line[i] == 39))
        {
            i = quote_sizing(&data->line[i]);
			data->parseur.check = true;
            if (i == -1)
                return (i);
        }
		i++;
	}
	data->index = i;
	token = alt_string(data, token, i);
	return (SUCCESS);
}
