/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faherrau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:56:22 by faherrau          #+#    #+#             */
/*   Updated: 2021/05/21 17:59:23 by faherrau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

size_t	fh_strlen(const char *s)
{
	size_t length;

	if (!s)
		return (0);
	length = 0;
	while (s[length])
		length++;
	return (length);
}

size_t	fh_strcpy(char *dst, const char *src)
{
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
		return (0);
	src_len = fh_strlen(src);
	i = 0;
	while (i < src_len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_len);
}

char	*fh_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	int		concat_size;

	if (!s1 && !s2)
		return (NULL);
	concat_size = fh_strlen(s1) + fh_strlen(s2) + 1;
	if (!(concat = malloc(concat_size * sizeof(char))))
	{
		free((void *)s1);
		return (NULL);
	}
	fh_strcpy(concat, s1);
	fh_strcpy(&concat[fh_strlen(s1)], s2);
	free((void *)s1);
	return (concat);
}

int		contains(char *str, char c)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
