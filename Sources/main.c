/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faherrau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:12:43 by faherrau          #+#    #+#             */
/*   Updated: 2021/05/19 17:21:30 by faherrau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_all(t_data *data)
{
	wrdestroy();
	exit(0);
}

void	init_structure(t_data *data)
{
	data->line = NULL;
}

void	recover_data(t_data *data, char *line)
{
	if (ft_strcmp("exit", line) == SUCCESS)
		free_all(data);
	else if (ft_strcmp("pwd", line) == SUCCESS)
		ft_pwd();
	else
		printf("zsh: command not found: ", line, "\n");
}

int	str_error(t_data *data, char *str)
{
	free_all(data);
	ft_putstr(str);
}

int	main(void) // int ac, char **av, char **env
{
	t_data	data;
	char	*line;
	int		ret;

	init_structure(&data);
	while (1)
	{
		ft_putstr("\033[3;34mprompt : \033[0m");
		ret = get_next_line(1, &line);
		if (ret == -1)
			return (EXIT_FAILURE);
		recover_data(&data, line);
		free(line);
	}
	return (EXIT_SUCCESS);
}
