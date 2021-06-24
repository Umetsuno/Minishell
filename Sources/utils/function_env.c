/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 10:10:42 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/24 15:55:34 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

int	get_size_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**copy_env(char **env)
{
	int		i;
	char	**new_env;

	i = 0;
	new_env = NULL;
	i = get_size_env(env);
	new_env = malloc(sizeof(char *) * (i + 1));
	new_env[i] = 0;
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	return (new_env);
}

void	copy_env_add_one(t_data *data, char *new_elem)
{
	int		i;
	char	**env;

	i = 0;
	env = copy_env(data->env);
	free_double_etoile(data->env);
	i = get_size_env(env);
	data->env = malloc(sizeof(char *) * (i + 2));
	data->env[i] = 0;
	i = 0;
	while (env[i])
	{
		data->env[i] = ft_strdup(env[i]);
		i++;
	}
	data->env[i] = ft_strdup(new_elem);
	free_double_etoile(env);
}

void	copy_env_del_one(t_data *data, int index_elem_to_del)
{
	int		i;
	int		size_env;
	char	**env;

	i = 0;
	env = copy_env(data->env);
	free_double_etoile(data->env);
	size_env = get_size_env(env);
	data->env = malloc(sizeof(char *) * (size_env));
	data->env[size_env] = 0;
	while (i < size_env)
	{
		if (i != index_elem_to_del)
			data->env[i] = ft_strdup(env[i]);
		i++;
	}
	free_double_etoile(env);
}
