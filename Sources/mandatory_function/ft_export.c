/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:18:00 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/09 19:24:23 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

// static int	get_size_env(t_data *data)
// {
// 	return (lstsize(data));
// }

// static int	add_elem_to_env(t_data *data, char *elem, int last_elem_env)
// {
// 	data->env[last_elem_env] = ft_strdup(elem);
// 	data->env[last_elem_env + 1] = 0;
// 	last_elem_env++;
// 	return (last_elem_env);
// }

void	ft_export(t_data *data)
{
	// int	index;
	// int	last_elem_env;
	// int	j;
	// int error;

	data->index = 0;
	// j = 1;
	// last_elem_env = get_size_env(data);
	// while (data->parsing.argument[j])
	// {
	// 	index = 0;
	// 	error = 0;
	// 	while (data->parsing.argument[j][index])
	// 	{
	// 		if (data->parsing.argument[j][index] == '=' && data->parsing.argument[j][index - 1] == ' ')
	// 			error = ft_strerror_export("export:", data->parsing.argument[j], "not a valid identifier\n");
	// 		index++;
	// 	}
	// 	if (error == 0)
	// 		last_elem_env = add_elem_to_env(data, data->parsing.argument[j], last_elem_env);
	// 	j++;
	// 	skip_space_i(data->parsing.argument[index], &index);
	// }
	// ft_env(data);
}
