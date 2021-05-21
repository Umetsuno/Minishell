/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faherrau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:12:43 by faherrau          #+#    #+#             */
/*   Updated: 2021/05/21 18:31:24 by faherrau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/MiniShell.h"

void	free_all(char *line)
{
	if (line)
		free(line);
	exit(0);
}

void	init_structure(t_data *data)
{
	data->line = NULL;
}

void	recover_data(char *line)
{
	if (ft_strcmp("exit", line) == SUCCESS)
		free_all(line);
	else if (ft_strcmp("pwd", line) == SUCCESS)
		ft_pwd();
	else
		printf("zsh: command not found: %s\n", line);
}

int	main(void) // int ac, char **av, char **env
{
	t_data	data;
	char	*line;
	int		ret;

	init_structure(&data);
	while (1)
	{
		dprintf(1, "\033[3;34mprompt : \033[0m");
		ret = get_next_line(1, &line);
		if (ret == -1)
			return (EXIT_FAILURE);
		/* line = strtrim_space(line); Weird bug*/
		recover_data(line);
		free(line);
	}
	return (EXIT_SUCCESS);
}
