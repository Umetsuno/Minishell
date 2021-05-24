/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:06:21 by sbaranes          #+#    #+#             */
/*   Updated: 2021/05/24 18:45:45 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	ft_env(t_data *data)
{
	int index;

	index = 0;
	if (data->env[0] == NULL)
		errno = 127;
	else
	{
		while (data->env[index])
		{
			printf("%s\n",data->env[index]);
			index++;
		}
		errno = 0;
	}
}
