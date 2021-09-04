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

int	size_env(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return (i);
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
	if (!env)
		return (new_env);
	i = size_env(env);
	new_env = ft_calloc((i + 1), sizeof(char *));
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
	int		j;
	char	**env;

	j = 0;
	env = NULL;
	i = size_env(data->env);
	env = ft_calloc((i + 2), sizeof(char *));
	while (j < i)
	{
		env[j] = ft_strdup(data->env[j]);
		j++;
	}
	env[j] = ft_strdup(new_elem);
	j++;
	env[j] = 0;
	free_double_etoile(data->env);
	data->env = env;
}

void	copy_env_del_one(t_data *data, int index_elem_to_del)
{
	int		i;
	int		j;
	int		s_env;
	char	**env;

	i = 0;
	j = 0;
	s_env = size_env(data->env);
	env = ft_calloc((s_env + 1), sizeof(char *));
	env[s_env] = NULL;
	env[s_env - 1] = NULL;
	while (i < s_env)
	{
		if (i != index_elem_to_del)
		{
			env[j] = ft_strdup(data->env[i++]);
			j++;
		}
		else
			i++;
	}
	free_double_etoile(data->env);
	data->env = env;
}
