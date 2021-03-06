/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:40:38 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/31 14:16:25 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	x;

	if (dest == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	else
	{
		x = 0;
		while (x < size - 1 && src[x])
		{
			dest[x] = src[x];
			x++;
		}
		dest[x] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strcpy(char *dest, char *src)
{
	int	x;

	x = 0;
	while (src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}
