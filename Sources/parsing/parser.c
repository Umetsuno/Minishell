/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oghma <fabien@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:39:55 by oghma             #+#    #+#             */
/*   Updated: 2021/09/03 18:17:21 by oghma            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

int parsing_split(t_data *data)
{
	char	*token;

	token = NULL;
	/* ft_split sur les espaces */
	data->index = 0;
	if (ft_token(data, token) != SUCCESS)
		return (-1);
	while (token)
	{
		data->parseur.argument = (char **)ft_realloc(data->parseur.argument, \
			((data->index + 1) * sizeof(char *)));
		data->parseur.argument[data->index] = ft_strdup(token);
		free(token);
		if (ft_token(data, token) != SUCCESS)
			return (-1);
		data->index++;
	}
	/* Allocation d'un element qu'on met a NULL a la fin du tableau */
	data->parseur.argument = (char **)ft_realloc(data->parseur.argument, \
		((data->index + 1) * sizeof(char *)));
	data->parseur.argument[data->index] = NULL;
	return (SUCCESS);
}
