/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_numb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:06:14 by sbaranes          #+#    #+#             */
/*   Updated: 2021/03/24 10:19:02 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

short	ft_isnumber(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t	atoi_numb(char *str, size_t *i)
{
	int		result;

	result = 0;
	while (ft_isnumber(str[*i]))
	{
		result = result * 10 + (str[*i] - '0');
		*i += 1;
	}
	return (result);
}
