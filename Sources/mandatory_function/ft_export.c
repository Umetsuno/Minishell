/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:18:00 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/22 14:44:07 by sbaranes         ###   ########lyon.fr   */
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
		i++;
	}
	return (false);
}

void	add_elem_to_env(t_data *data, char *elem)
{
	if (check_if_already_exists(data, elem) == true)
		return ;
	copy_env_add_one(data, elem);
}

void	print_export(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		printf("declare -x %s\n", data->env[i]);
		i++;
	}
}

void	ft_export(t_data *data)
{
	int	i;

	i = 1;
	errno = 0;
	if (!data->parsing.argument[1])
		print_export(data);
	while (data->parsing.argument[i])
	{
		if (data->parsing.argument[i][0] == '=' ||
			ft_isnumber(data->parsing.argument[i][0]))
			ft_strerror_export("export", data->parsing.argument[i], "not a valid identifier\n");
		else
		{
			puts("here");
			puts(data->parsing.argument[i]);
			add_elem_to_env(data, data->parsing.argument[i]);
			puts("here2");
		}
		i++;
	}
}
