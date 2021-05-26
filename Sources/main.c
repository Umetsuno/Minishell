/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:12:43 by faherrau          #+#    #+#             */
/*   Updated: 2021/05/26 19:31:35 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/MiniShell.h"


int		is_builting_cmd(t_data *data)
{
	if (ft_strcmp("exit", data->line) == SUCCESS)
		return (true);
	else if (ft_strcmp("pwd", data->line) == SUCCESS)
		return (true);
	else if (ft_strcmp("env", data->line) == SUCCESS)
		return (true);
	else
		return (false);
}

void	recover_data(t_data *data)
{
	/* parsing fab */
	if (is_builting_cmd(data) == true)
		ft_exec_builting_cmd(data);
	else if (get_path(data) == SUCCESS)
		ft_exec_path(data);
	else
	{
		printf("bash: %s: command not found\n", data->line);
		errno = 127;
	}
}

int	ft_strerror(char *str)
{
	write(1, &str[0], ft_strlen(str));
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		ret;

	init_structure(&data, av);
	data.env = env;
	data.line = NULL;
	if (ac != 1)
		return (ft_strerror("Argument Error: wrong number of arguments.\n"));
	while (1)
	{
		build_pwd(&data);
		dprintf(1, "\033[3;34mprompt : \033[0m");
		ret = get_next_line(1, &data.line);
		if (ret == -1)
			return (EXIT_FAILURE);
		data.line = strtrim_space(data.line);
		recover_data(&data);
		free(data.line);
	}
	return (EXIT_SUCCESS);
}
