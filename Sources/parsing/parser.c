/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oghma <fabien@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:39:55 by oghma             #+#    #+#             */
/*   Updated: 2021/09/03 20:04:27 by oghma            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	print_tab(t_data *data)
{
	int i = 0;

	printf("\nStart print tab :\n");
	while (data->parseur.argument[i])
	{
		printf("tab %d = '%s'\n", i, data->parseur.argument[i]);
		i++;
	}
	printf("\nEnd print tab\n");
}

int parsing_split(t_data *data)
{
	data->parseur.token = NULL;
	data->index = 0;
	if (ft_token(data) != SUCCESS)
		return (-1);
	data->index++;
	while (data->line[data->index])
	{
		ft_realloc_tab(data);
		if (ft_token(data) != SUCCESS)
			return (-1);
		data->index++;
	}
	ft_realloc_tab(data);
	print_tab(data);
	return (SUCCESS);
}
