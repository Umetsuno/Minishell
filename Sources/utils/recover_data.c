/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:12:56 by sbaranes          #+#    #+#             */
/*   Updated: 2021/09/03 19:37:17 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	cmd_check_cmd(t_data *data)
{
	if (check_if_have_cmd(data) == true)
		cmd_split_cmd(data);
	else
		data->all_cmd = new_cmd_parsing(data->parseur.argument);
	free_tab_arg(data);
}

void	check_pipe(t_data *data)
{
	if (check_if_have_pipe(data) == true)
		split_cmd(data);
	else
		data->cmd = new_cmd_parsing(data->all_cmd->argument);
}

void	recover_data(t_data *data)
{
	// if (parsing_split(data) == -1)
	// {
	// 	/* GESTION D'ERREURS PERSONNALISEES */
	// 	return ;
	// }
	parsing_split(data);
	// data->parseur.argument = ft_split(data->line, ' ');
	data->index = 0;
	cmd_check_cmd(data);
	data->save_all_cmd = data->all_cmd;
	while (data->all_cmd)
	{
		check_pipe(data);
		data->save_cmd = data->cmd;
		if (data->check_pipe == false)
			exe_cmd(data);
		else
			exe_pipe(data);
		cmdclear(data);
		data->all_cmd = data->all_cmd->next;
		init_start_loop(data);
	}
	big_cmdclear(data);
}
