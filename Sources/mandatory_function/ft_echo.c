/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:00:49 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/11 14:35:06 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	ft_echo(t_data *data)
{
	int	index;
	int	flag;

	index = 1;
	flag = 0;
	while (data->cmd->argument[index] && (strcmp("-n", data->cmd->argument[index]) == 0))
	{
		flag++;
		data->nonewline = true;
		index++;
	}
	while (data->cmd->argument[index])
	{
		if (!strcmp("$?", data->cmd->argument[index]))
			ft_putnbr(errno);
		else
			ft_putstr(data->cmd->argument[index]);
		if (data->cmd->argument[index + 1])
			ft_putstr(" ");
		index++;
	}
	if (flag == 0)
		ft_putstr("\n");
	errno = 0;
}
