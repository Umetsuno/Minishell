/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:41:43 by sbaranes          #+#    #+#             */
/*   Updated: 2021/05/18 12:46:04 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putstr(char const *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_triple_putstr(char *s1, char *s2, char *s3)
{
	int	i;

	i = 0;
	if (s1)
	{
		while (s1[i])
			write(1, &s1[i++], 1);
	}
	i = 0;
	if (s2)
	{
		while (s2[i])
			write(1, &s2[i++], 1);
	}
	i = 0;
	if (s3)
	{
		while (s3[i])
			write(1, &s3[i++], 1);
	}
}
