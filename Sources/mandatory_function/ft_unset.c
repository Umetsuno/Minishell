/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:18:37 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/11 11:30:03 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	ft_unset(t_data *data)
{
	int	i;
	int	j;
	int	size_elem;

	i = 1;
	while (data->parsing->argument[i])
	{
		j = 0;
		size_elem = ft_strlen(data->parsing->argument[i]);
		while (data->env[j])
		{
			if (ft_strncmp(data->env[j], data->parsing->argument[i], size_elem) == 0)
			{
				copy_env_del_one(data, j);
				break ;
			}
			j++;
		}
		i++;
	}
	errno = 0;
}
