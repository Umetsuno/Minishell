/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:39:55 by oghma             #+#    #+#             */
/*   Updated: 2021/09/09 11:14:18 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

int	parsing_split(t_data *data)
{
	data->parseur.token = NULL;
	data->index = 0;
	while (data->line[data->index])
	{
		if (ft_token(data) != SUCCESS)
			return (-1);
		ft_realloc_tab(data);
		if (data->line[data->index] != '\0')
			data->index++;
	}
	return (SUCCESS);
}
