/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:01:50 by sbaranes          #+#    #+#             */
/*   Updated: 2021/09/03 17:44:48 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	init_structure(t_data *data)
{
	data->save_fd = dup(1);
	data->temp_fd = 1;
	data->line = NULL;
	data->path = NULL;
	data->path_pwd = NULL;
	data->path_split = NULL;
	data->path_oldpwd = NULL;
	data->in_cmd = false;
	data->nonewline = false;
	data->check_pipe = false;
	data->cmd = NULL;
	data->all_cmd = NULL;
	data->save_all_cmd = NULL;
	data->error = false;
	data->del_temp = false;
	data->already = false;
	data->index = 0;
	data->parseur.start = 0;
	data->parseur.argument = NULL;
	init_ptr(data->f);
}

void	init_start_loop(t_data *data)
{
	free_tab_arg(data);
	data->error = false;
	data->already = false;
	data->check_pipe = false;
	data->parseur.start = 0;
	data->index = 0;
	replace_fd(data);
	build_pwd(data);
	if (data->in_cmd == true && data->nonewline != true)
		printf("\r");
	data->in_cmd = false;
	data->nonewline = false;
	if (data->del_temp == true)
		remove("tp_file");
	data->del_temp = false;
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
