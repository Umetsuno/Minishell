/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:13:04 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/31 14:13:05 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

static int	cmd_not_compatible(char *cmd)
{
	if (ft_strcmp("echo", cmd) == SUCCESS)
		return (false);
	else if (ft_strcmp("ls", cmd) == SUCCESS)
		return (false);
	else
		return (true);
}

void	get_data_input(t_data *data, char *name, char **new_arg)
{
	char	*line;
	int		fd;

	line = NULL;
	data->del_temp = true;
	fd = open("tp_file", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (ft_strcmp(name, line) == SUCCESS)
			break ;
		else
		{
			ft_putstr_fd(line, fd);
			ft_putstr_fd("\n", fd);
		}
		free(line);
	}
	free(line);
	if (cmd_not_compatible(data->cmd->cmd))
		new_arg[data->index++] = ft_strdup("tp_file");
	close(fd);
}

void	get_input(t_data *data, char *name, char **new_arg, int nb_of_chevron)
{
	if (data->already)
	{
		data->index--;
		free(new_arg[data->index]);
	}
	data->already = true;
	if (ft_strcmp(new_arg[data->index - 1], data->cmd->cmd))
		return ;
	if (nb_of_chevron == 1)
	{
		if (check_path(name) == SUCCESS)
		{
			if (cmd_not_compatible(data->cmd->cmd))
				new_arg[data->index++] = ft_strdup(name);
		}
		else
		{
			ft_strerror(name, NULL, "No such file or directory\n");
			data->error = true;
		}
	}
	else if (nb_of_chevron == 2)
		get_data_input(data, name, new_arg);
}

int	scan_input(t_data *data)
{
	char	**new_arg;
	int		i;

	new_arg = malloc(sizeof(char *) * (size_env(data->cmd->argument) + 1));
	i = -1;
	data->index = 0;
	while (data->cmd->argument[++i])
	{
		if (!strcmp("<", data->cmd->argument[i]))
		{
			get_input(data, data->cmd->argument[i + 1], new_arg, 1);
			i++;
		}
		else if (!strcmp("<<", data->cmd->argument[i]))
		{
			get_input(data, data->cmd->argument[i + 1], new_arg, 2);
			i++;
		}
		else
			new_arg[data->index++] = ft_strdup(data->cmd->argument[i]);
	}
	new_arg[data->index] = 0;
	free_double_etoile(data->cmd->argument);
	data->cmd->argument = new_arg;
	return (data->error);
}
