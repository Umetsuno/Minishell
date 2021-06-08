/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:18:37 by sbaranes          #+#    #+#             */
/*   Updated: 2021/05/24 18:46:35 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	ft_unset(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->env[i])
	{
		j = 0;
		while (data->parsing.argument[j])
		{
			if (!strncmp(data->env[i], data->parsing.argument[j], ft_strlen(data->parsing.argument[j])))
			{
				data->env[i] = 0;
			}
			j++;
		}
		i++;
	}
	
}
