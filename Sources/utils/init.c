/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:01:50 by sbaranes          #+#    #+#             */
/*   Updated: 2021/05/26 19:30:59 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	init_structure(t_data *data, char **av)
{
	*av = NULL;
	data->line = NULL;
	data->env = NULL;
	data->path = NULL;
	data->path_pwd = NULL;
	data->path_split = NULL;
	data->parsing.cmd = NULL;
	data->parsing.line = NULL;
	data->parsing.flag = NULL;
	data->parsing.argument = NULL;
	init_ptr(data->f);
}

void	init_ptr(void (*f[8])(t_data*))
{
	f[FCT_EXIT] = &free_minishell;
	f[FCT_CD] = &ft_cd;
	f[FCT_ECHO] = &ft_echo;
	f[FCT_ENV] = &ft_env;
	f[FCT_EXPORT] = &ft_export;
	f[FCT_PWD] = &ft_pwd;
	f[FCT_UNSET] = &ft_unset;
}
