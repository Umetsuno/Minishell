/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oghma <fabien@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:22:11 by sbaranes          #+#    #+#             */
/*   Updated: 2021/09/03 18:16:55 by oghma            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	replace_fd(t_data *data)
{
	if (data->temp_fd != data->save_fd)
	{
		close(data->temp_fd);
		dup2(data->save_fd, 1);
	}
	data->temp_fd = 1;
}

static void	swap_fd(t_data *data, char *name, int nb_of_chevron)
{
	int		output_fd;

	output_fd = data->temp_fd;
	if (nb_of_chevron == 1)
		output_fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (nb_of_chevron == 2)
		output_fd = open(name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (output_fd != data->temp_fd)
		close(data->temp_fd);
	data->temp_fd = output_fd;
	dup2(output_fd, 1);
}

void	scan_fd(t_data *data)
{
	char	**new_arg;
	int		i;

	new_arg = ft_calloc((size_env(data->cmd->argument) + 1), sizeof(char *));
	i = -1;
	data->index = 0;
	while (data->cmd->argument[++i])
	{
		if (!strcmp(">", data->cmd->argument[i]))
		{
			swap_fd(data, data->cmd->argument[i + 1], 1);
			i++;
		}
		else if (!strcmp(">>", data->cmd->argument[i]))
		{
			swap_fd(data, data->cmd->argument[i + 1], 2);
			i++;
		}
		else
			new_arg[data->index++] = ft_strdup(data->cmd->argument[i]);
	}
	new_arg[data->index] = 0;
	free_double_etoile(data->cmd->argument);
	data->cmd->argument = new_arg;
}
