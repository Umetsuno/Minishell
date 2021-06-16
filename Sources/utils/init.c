/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:01:50 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/16 15:03:35 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	copy_env(t_data *data, char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	data->env = malloc(sizeof(char *) * (i + 1));
	data->env[i] = 0;
	i = 0;
	while (env[i])
	{
		data->env[i] = ft_strdup(env[i]);
		i++;
	}
}

void	copy_env_add_one(t_data *data, char *new_elem)
{
	int		i;
	char	**env;

	i = 0;
	env = data->env;

	while (env[i])
		i++;
	data->env = malloc(sizeof(char *) * (i + 1));
	data->env[i] = 0;
	i = 0;
	while (env[i])
	{
		data->env[i] = ft_strdup(env[i]);
		i++;
	}
}

void	init_structure(t_data *data, char **av)
{
	*av = NULL;
	data->line = NULL;
	data->path = NULL;
	data->path_pwd = NULL;
	data->path_split = NULL;
	data->parsing.cmd = NULL;
	data->parsing.line = NULL;
	data->path_oldpwd = NULL;
	data->parsing.argument = NULL;

	init_ptr(data->f);
}

void	init_ptr(void (*f[8])(t_data*))
{
	f[FCT_EXIT] = &free_minishell;
	f[FCT_PWD] = &ft_pwd;
	f[FCT_ENV] = &ft_env;
	f[FCT_CD] = &ft_cd;
	f[FCT_UNSET] = &ft_unset;
	f[FCT_ECHO] = &ft_echo;
	f[FCT_EXPORT] = &ft_export;
}
