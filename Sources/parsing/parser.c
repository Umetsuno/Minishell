/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:39:55 by oghma             #+#    #+#             */
/*   Updated: 2021/09/03 19:56:15 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	print_tab(char **tab)
{
	int i = 0;

	printf("\nStart print tab ;\n");
	while (tab[i])
	{
		printf("tab %d = '%s'\n", i, tab[i]);
		i++;
	}
	printf("\nEnd print tab ;\n");
}



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
		data->parseur.argument = ft_realloc_tab(data->parseur.argument);
		data->parseur.argument[data->index] = ft_strdup(token);
		free(token);
		if (ft_token(data, token) != SUCCESS)
			return (-1);
		data->index++;
	}
	/* Allocation d'un element qu'on met a NULL a la fin du tableau */
	data->parseur.argument = ft_realloc_tab(data->parseur.argument);
	data->parseur.argument[data->index] = NULL;
	return (SUCCESS);
}
