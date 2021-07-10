/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:00:49 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/29 17:47:29 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	ft_echo(t_data *data)
{
	int	index;
	int	flag;

	index = 1;
	flag = 0;
	while (data->parsing.argument[index] && (strcmp("-n", data->parsing.argument[index]) == 0))
	{
		flag++;
		data->nonewline = true;
		index++;
	}
	while (data->parsing.argument[index])
	{
		if (!strcmp("$?", data->parsing.argument[index]))
			ft_putnbr(errno);
		else
			ft_putstr(data->parsing.argument[index]);
		if (data->parsing.argument[index + 1])
			ft_putstr(" ");
		index++;
	}
	if (flag == 0)
		ft_putstr("\n");
	errno = 0;
}
