/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:00:49 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/10 17:21:34 by sbaranes         ###   ########lyon.fr   */
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
		index++;
	}
	while (data->parsing.argument[index])
	{
		if (!strcmp("$?", data->parsing.argument[index]))
			ft_putnbr_fd(errno, 1);
		else
			ft_putstr_fd(data->parsing.argument[index], data->fd);
		ft_putstr_fd(" ", data->fd);
		index++;
	}
	if (flag == 0)
		ft_putstr_fd("\n", data->fd);
	errno = 0;
}
