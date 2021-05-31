/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:01:50 by sbaranes          #+#    #+#             */
/*   Updated: 2021/05/27 15:44:57 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	init_structure(t_data *data, char **av, char **env)
{
	*av = NULL;
	data->env = env;
	data->line = NULL;
	data->env = NULL;
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
