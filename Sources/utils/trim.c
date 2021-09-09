/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:11:49 by faherrau          #+#    #+#             */
/*   Updated: 2021/09/09 10:51:55 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

char	*strtrim_space(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	new_str = NULL;
	if (str[i] != ' ')
		return (str);
	while (str[i] == ' ')
		i++;
	j = (ft_strlen(str) - i);
	new_str = ft_calloc((j + 1), sizeof(char));
	j = 0;
	while (str[i])
	{
		new_str[j] = str[i];
		j++;
		i++;
	}
	new_str[j] = 0;
	free(str);
	return (new_str);
}
