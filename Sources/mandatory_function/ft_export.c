/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:18:00 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/24 15:48:24 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

static bool	check_if_already_exists(t_data *data, char *elem)
{
	int i;

	i = 0;
	while (data->env[i])
	{
		if (!strncmp(data->env[i], elem, ft_strlen(elem)))
			return (true);
		else if (!strncmp(elem, data->env[i], ft_strlen(data->env[i])))
		{
			copy_env_del_one(data, i);
			return (false);
		}
		i++;
	}
	return (false);
}

static void	add_elem_to_env(t_data *data, char *elem)
{
	if (check_if_already_exists(data, elem) == true)
		return ;
	copy_env_add_one(data, elem);
}

static void	print_export(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		printf("declare -x (%d) %s\n", i, data->env[i]);
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
			add_elem_to_env(data, data->parsing.argument[i]);
		i++;
	}
}
