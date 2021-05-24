/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:12:43 by faherrau          #+#    #+#             */
/*   Updated: 2021/05/24 19:23:07 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/MiniShell.h"
void	free_all(t_data *data)
{
	if (data->line)
		free(data->line);
	exit(0);
}

void	init_ptr(void (*f[8])(t_data*))
{
	f[FCT_EXIT] = &free_all;
	f[FCT_CD] = &ft_cd;
	f[FCT_ECHO] = &ft_echo;
	f[FCT_ENV] = &ft_env;
	f[FCT_EXPORT] = &ft_export;
	f[FCT_PWD] = &ft_pwd;
	f[FCT_UNSET] = &ft_unset;
}

void	init_structure(t_data *data, char **av)
{
	*av = NULL;
	data->line = NULL;
	init_ptr(data->f);
}

void	recover_data(t_data *data)
{
	if (ft_strcmp("exit", data->line) == SUCCESS)
		data->f[FCT_EXIT](data);
	else if (ft_strcmp("pwd", data->line) == SUCCESS)
		data->f[FCT_PWD](data);
	else if (ft_strcmp("env", data->line) == SUCCESS)
		data->f[FCT_ENV](data);
	else
		printf("bash: %s: command not found\n", data->line);
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
