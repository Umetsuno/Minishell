/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:37:28 by sbaranes          #+#    #+#             */
/*   Updated: 2021/05/31 18:02:43 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

char	*ft_strcat(char *dest, char *src)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (dest)
	{
		while (dest[x])
		x++;
	}
	while (src[y])
		dest[x++] = src[y++];
	dest[x] = '\0';
	return (dest);
}

static void	ft_concate(char *tmp, t_data *data, int index)
{
		ft_strcat(tmp, data->path_split[index]);
		ft_strcat(tmp, "/");
		ft_strcat(tmp, data->parsing.cmd);
}

int	check_path(char *path)
{
	struct stat buffer;
	int check;

	check = stat(path, &buffer);
	if(check == 0)
		return (SUCCESS);
	else
		return (FAILURE);
}

char	*do_split_path(t_data *data)
{
	int		index;
	char	*tmp;

	index = 0;
	tmp = NULL;
	data->path_split = ft_split(data->path, ':');
	while (data->path_split[index])
	{
		tmp = ft_calloc(sizeof(char), ((ft_strlen(data->path_split[index]) + strlen(data->parsing.cmd) + 2)));
		if (tmp == NULL)
			return (NULL);
		ft_concate(tmp, data, index);
		if (check_path(tmp) == SUCCESS)
		{
			if (data->parsing.cmd)
				wrfree(data->parsing.cmd);
			break ;
		}
		free(tmp);
		tmp = NULL;
		index++;
	}
	free_double_etoile(data->path_split);
	return (tmp);
}

int	get_path(t_data *data)
{
	data->index = -1;
	if (data->parsing.cmd[0] != '/' && ft_strncmp(data->parsing.cmd, "./", 2) != 0)
	{
		data->path = getenv("PATH");
		if (data->path == NULL)
			return (FAILURE);
		data->parsing.cmd = do_split_path(data);
		if (data->parsing.cmd == NULL)
			return (FAILURE);
	}
	if (data->parsing.cmd)
		return (SUCCESS);
	return (FAILURE);
}
