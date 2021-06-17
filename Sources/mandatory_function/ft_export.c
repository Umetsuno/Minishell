/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:18:00 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/17 14:05:23 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"



bool	check_if_already_exists(t_data *data, char *elem)
{
	int i;

	i = 0;
	while (data->env[i])
	{
		if (!strcmp(data->env[i], elem))
			return (true);
	}
	return (false);
}

void	add_elem_to_env(t_data *data, char *elem)
{
	int	i;
	int	last_index_env;

	i = 0;
	last_index_env = get_size_env(data);
	if (check_if_already_exists(data, elem) == true)
		return ;

}

void	ft_export(t_data *data)
{
	// int	i;

	// i = 0;
	// errno = 0;
	// if (!data->parsing.argument[1])
	// 	print_export(data);
	// while (data->parsing.argument[i])
	// {
	// 	if (data->parsing.argument[i][0] == '=' ||
	// 		ft_isnumber(data->parsing.argument[i][0]))
	// 		ft_strerror_export("export", data->parsing.argument[i], "not a valid identifier\n");
	// 	else
	// 		add_elem_to_env(data, data->parsing.argument[i]);
	// 	i++;
	// }
}
