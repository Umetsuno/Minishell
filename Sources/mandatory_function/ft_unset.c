/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:18:37 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/24 14:54:28 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	ft_unset(t_data *data)
{
	int	i;
	int	j;
	int	size_elem;

	i = 1;
	while (data->parsing.argument[i])
	{
		j = 0;
		size_elem = ft_strlen(data->parsing.argument[i]);
		while (data->env[j])
		{
			if (ft_strncmp(data->env[j], data->parsing.argument[i], size_elem) == 0)
			{
				puts("avant fonction");
				copy_env_del_one(data, j);
				puts("check apres fonction");
				int o = 0;
				while (data->env[o])
				{
					printf("ligne %d = '%s'\n", o, data->env[o]);
					o++;
				}
				puts("fin de if");
			}
			j++;
		}
		i++;
	}
	errno = 0;
}
