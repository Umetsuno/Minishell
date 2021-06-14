/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:11:49 by faherrau          #+#    #+#             */
/*   Updated: 2021/06/14 20:26:07 by sbaranes         ###   ########lyon.fr   */
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
	while (str[i] == ' ')
		i++;
	j = (ft_strlen(str) - i);
	new_str = malloc(sizeof(char) * j + 1);
	j = 0;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = 0;
	free(str);
	return (new_str);
}
