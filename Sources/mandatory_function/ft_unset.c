/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:18:37 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/23 10:44:24 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	ft_unset(t_data *data)
{
	int	i;
	int	j;
	int	size_elem;

	i = 1;
	j = 0;
	while (data->parsing.argument[i])
	{
		j = 0;
		size_elem = ft_strlen(data->parsing.argument[i]);
		while (data->env[j])
		{
			if (!ft_strncmp(data->env[j], data->parsing.argument[i], size_elem))
				copy_env_del_one(data, data->parsing.argument[i], j);
			j++;
		}
		i++;
	}
	errno = 0;
}
