/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:51:27 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/08 14:51:30 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	ft_strerror(char *s1, char *s2, char *s3)
{
	write(2, "bash: ", 6);
	if (s1)
	{
		write(2, s1, ft_strlen(s1));
		write(2, ": ", 2);
	}
	if (s2)
	{
		write(2, s2, ft_strlen(s2));
		write(2, ": ", 2);
	}
	if (s3)
	{
		write(2, s3, ft_strlen(s3));
	}
	
}

int	ft_strerror_export(char *s1, char *s2, char *s3)
{
	write(2, "bash: ", 6);
	if (s1)
	{
		write(2, s1, ft_strlen(s1));
		write(2, ": ", 2);
	}
	if (s2)
	{
		write(2, "`", 1);
		write(2, s2, ft_strlen(s2));
		write(2, "'", 1);
		write(2, ": ", 2);
	}
	if (s3)
	{
		write(2, s3, ft_strlen(s3));
	}
	errno = 1;
	return (1);
}

int	ft_error_arg(char *str)
{
	write(1, &str, ft_strlen(str));
	return (1);
}
