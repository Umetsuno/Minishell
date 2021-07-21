/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:01:50 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/29 17:45:42 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	init_structure(t_data *data, char **av)
{
	*av = NULL;
	data->save_fd = dup(1);
	data->temp_fd = 1;
	data->line = NULL;
	data->path = NULL;
	data->path_pwd = NULL;
	data->path_split = NULL;
	data->parsing.cmd = NULL;
	data->parsing.line = NULL;
	data->path_oldpwd = NULL;
	data->parsing.argument = NULL;
	data->in_cmd = false;
	data->nonewline = false;
	init_ptr(data->f);
}

void	init_start_loop(t_data *data)
{
	data->error = false;
	data->del_temp = false;
	replace_fd(data);
	build_pwd(data);
	if (data->in_cmd == true && data->nonewline != true)
		printf("\r");
	data->in_cmd = false;
	data->nonewline = false;
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
