/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:12:43 by faherrau          #+#    #+#             */
/*   Updated: 2021/08/12 18:19:03 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/MiniShell.h"

void	do_prompt(t_data *data)
{
	while (1)
	{
		init_start_loop(data);
		data->line = readline("\033[4;34mMyBash-2.0$ \033[0m");
		add_history(data->line);
		if (data->line == NULL)
		{
			ft_putstr("\r\033[4;34mMyBash-2.0$ \033[0m");
			data->line = ft_strdup("exit");
		}
		data->line = strtrim_space(data->line);
		if (ft_strlen(data->line) == 0)
			do_prompt(data);
		data->index = 1;
		recover_data(data);
		free(data->line);
		if (data->del_temp == true)
			remove("temp_file");
	}
}

int	main(int ac, char **av, char **env)
{
	init_structure(&g_data, av);
	g_data.env = copy_env(env);
	signal(SIGINT, sig_ctrl_c);
	signal(SIGQUIT, sig_ctrl_bs);
	if (ac != 1)
		return (ft_error_arg("Argument Error: wrong number of arguments.\n"));
	do_prompt(&g_data);
	return (EXIT_SUCCESS);
}
