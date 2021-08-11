/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:12:43 by faherrau          #+#    #+#             */
/*   Updated: 2021/08/11 18:19:39 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/MiniShell.h"

void	check_arg(t_data *data)
{
	if (check_if_have_pipe(data) == true)
		split_cmd(data);
	else
		data->all_cmd = new_cmd_parsing(data->parseur.argument);
	free_double_etoile(data->parseur.argument);
}

void	recover_data(t_data *data)
{
	/* parsing fab */
	// parser(data);
	/* temporaire */ data->parseur.argument = ft_split(data->line, ' ');
	/* parsing fab */
	check_arg(data);
	data->cmd = data->all_cmd;
	if (data->p.pipe == false)
		exe_cmd(data);
	else
		exe_pipe(data);
	cmdclear(data);
}

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
