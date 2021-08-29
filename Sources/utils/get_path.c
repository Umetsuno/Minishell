/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:37:28 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/11 14:35:06 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

static void	ft_concate(char *tmp, t_data *data, int index)
{
	ft_strcat(tmp, data->path_split[index]);
	ft_strcat(tmp, "/");
	ft_strcat(tmp, data->cmd->cmd);
}

int	check_path(char *path)
{
	struct stat	buffer;
	int			check;

	check = stat(path, &buffer);
	if(check == 0)
		return (SUCCESS);
	else
		return (FAILURE);
}

static char	*do_split_path(t_data *data)
{
	int		index;
	char	*tmp;

	index = 0;
	tmp = NULL;
	data->path_split = ft_split(data->path, ':');
	while (data->path_split[index])
	{
		tmp = ft_calloc(sizeof(char), ((ft_strlen(data->path_split[index]) + strlen(data->cmd->cmd) + 2)));
		if (tmp == NULL)
			return (NULL);
		ft_concate(tmp, data, index);
		if (check_path(tmp) == SUCCESS)
		{
			if (data->cmd->cmd)
				free(data->cmd->cmd);
			break ;
		}
		free(tmp);
		tmp = NULL;
		index++;
	}
	if (!tmp)
		free(data->cmd->cmd);
	return (tmp);
}

int	get_path(t_data *data)
{
	data->index = -1;
	if (data->cmd->cmd[0] != '/' && ft_strncmp(data->cmd->cmd, "./", 2) != 0)
	{
		data->path = my_getenv(data, "PATH=");
		if (data->path == NULL)
			return (FAILURE);
		data->cmd->cmd = do_split_path(data);
		free_double_etoile(data->path_split);
		if (data->cmd->cmd == NULL)
			return (FAILURE);
	}
	if (data->cmd->cmd)
		return (SUCCESS);
	return (FAILURE);
}
