/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oghma <fabien@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:05:01 by oghma             #+#    #+#             */
/*   Updated: 2021/09/03 20:03:45 by oghma            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	ft_realloc_tab(t_data *data)
{
	int		i;
	int		j;
	char	**new_tab;

	j = 0;
	new_tab = NULL;
	i = size_env(data->parseur.argument);
	new_tab = ft_calloc((i + 2), sizeof(char *));
	while (j < i)
	{
		new_tab[j] = ft_strdup(data->parseur.argument[j]);
		j++;
	}
	new_tab[j] = ft_strdup(data->parseur.token);
	j++;
	new_tab[j] = NULL;
	free_tab_arg(data);
	free(data->parseur.token);
	data->parseur.token = NULL;
	data->parseur.argument = new_tab;
}
