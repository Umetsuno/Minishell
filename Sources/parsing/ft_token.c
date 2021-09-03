/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oghma <fabien@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:11:40 by oghma             #+#    #+#             */
/*   Updated: 2021/09/03 14:14:26 by oghma            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*alt_string(char *token, int start, int end, bool check)
{
	int i;

	i = 0;
	if (check == true)
	{
		start++;
		end--;
	}
	token = (char *)malloc(sizeof(char) * ((end - start) + 1));
	while (start < end)
	{
		token[i] = data->line[start];
		i++;
		start++;
	}
	token[i] = '\0';
	return (token);
}

int	ft_token(t_data *data, char c, char *token)
{
	int		i;
	int		start;
	bool 	check;

	i = data->index;
	start = i;
	check = false;
	while (data->line[i] && data->line[i] != ' ')
	{
		if ((data->line[i] == 34) || (data->line[i] == 39))
        {
            i = quote_sizing(&data->line[i]);
			check = true;
            if (i == -1)
                return (i);
        }
		i++;
	}
	data->index = i;
	token = copie_string(token, start, i, check);
}
