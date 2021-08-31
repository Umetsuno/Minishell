/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:38:49 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/31 14:16:45 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (dest)
	{
		while (dest[x])
			x++;
	}
	while (src[y])
		dest[x++] = src[y++];
	dest[x] = '\0';
	return (dest);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		t_dest;

	t_dest = ft_strlen(dest);
	i = 0;
	if (size <= t_dest)
		return (size + ft_strlen(src));
	while (t_dest + i < (size - 1) && src[i] != '\0')
	{
		dest[i + t_dest] = src[i];
		i++;
	}
	dest[i + t_dest] = '\0';
	return (t_dest + ft_strlen(src));
}
