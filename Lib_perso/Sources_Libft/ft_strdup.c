/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:36:34 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/22 15:51:31 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (src[x])
		x++;
	dest = ft_calloc(x + 1, sizeof(char));
	if (!dest)
		return (0);
	while (src[y])
	{
		dest[y] = src[y];
		y++;
	}
	dest[y] = '\0';
	return (dest);
}
