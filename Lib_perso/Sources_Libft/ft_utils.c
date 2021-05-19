/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:26:03 by sbaranes          #+#    #+#             */
/*   Updated: 2021/03/24 15:58:12 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	skip_space_t(char *str, size_t *i)
{
	while (str[*i] == ' ')
	{
		*i += 1;
	}
}

void	skip_space_i(char *str, int *i)
{
	while (str[*i] == ' ')
	{
		*i += 1;
	}
}

int	check_space_end(char *str, size_t *i)
{
	while (str[*i])
	{
		if (str[*i] != ' ')
			return (1);
		*i += 1;
	}
	return (0);
}

float	ft_abs(float a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}
