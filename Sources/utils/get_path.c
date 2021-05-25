/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:37:28 by sbaranes          #+#    #+#             */
/*   Updated: 2021/05/25 22:27:51 by sbaranes         ###   ########lyon.fr   */
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
		return 1;
	else
		return 0;
}

char	*do_split_path(t_data *data)
{
	int		index;
	char	*tmp;

	index = 0;
	tmp = NULL;
	data->path_split = ft_split(data->path, ':');
	free(data->path);
	while (data->path_split[index])
	{
		tmp = ft_calloc(sizeof(char), ((ft_strlen(data->path_split[index]) + strlen(data->parsing.cmd) + 2)));
		if (tmp == NULL)
			return (NULL);
		ft_concate(tmp, data, index);
		// if (check_path(tmp) == SUCCESS)
		// {
		// 	free(data->parsing.cmd);
		// 	break ;
		// }
		if (access(tmp, F_OK) == SUCCESS)
		{
			free(data->parsing.cmd);
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
	data->parsing.cmd = ft_calloc(sizeof(char), 3);
	data->parsing.argument = malloc(sizeof(char *) * 2);
	fh_strcpy(data->parsing.cmd, data->line);
	data->parsing.argument[0] = data->line;
	data->parsing.argument[2] = "coucou";
	data->parsing.argument[1] = NULL;
	if (data->parsing.cmd[0] != '/' && ft_strncmp (data->parsing.cmd, "./", 2) != 0)
	{
		while (data->env[++data->index])
		{
			if (!ft_strncmp(data->env[data->index] , "PATH=", 5))
			{
				data->path = ft_strdup(&data->env[data->index][5]);
				break ;
			}
		}
		if (data->path == NULL)
			return (FAILURE);
		data->parsing.cmd = do_split_path(data);
		puts(data->parsing.cmd);
		if (data->parsing.cmd == NULL)
			return (FAILURE);
	}
	if (data->parsing.cmd)
		return (SUCCESS);
	return (FAILURE);
}
