/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faherrau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:11:49 by faherrau          #+#    #+#             */
/*   Updated: 2021/05/21 17:22:45 by faherrau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

char	*strtrim_space(char *str)
{
	int i;
	int    i2;
	char *new_str;

	i = 0;
	while (str[i] == ' ')
		i++;
	i2 = i;
	while (str[i2])
		i2++;
	new_str = malloc(sizeof(char) * i2 + 1);
	i2 = 0;
	while (str[i])
		new_str[i2++] = str[i++];
	new_str[i2] = 0;
	free(str);
	return (new_str);
}
