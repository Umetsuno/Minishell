/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:18:00 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/16 12:55:47 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

static int	get_size_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
		i++;
	return (i);
}

void	ft_export(t_data *data)
{
	int	i;
	int	last_index_env;

	i = 0;
	last_index_env = get_size_env(data);
	errno = 0;
	if (!data->parsing.argument[1])
		put_put_all();
	while (data->parsing.argument[i])
	{
		if (data->parsing.argument[i][0] == '=' ||
			ft_isnumber(data->parsing.argument[i][0]))
			ft_strerror_export("export", data->parsing.argument[i], "not a valid identifier\n");
		else
		{

		}
		i++;
	}

}
