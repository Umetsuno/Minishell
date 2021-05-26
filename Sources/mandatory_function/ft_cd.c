/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:00:18 by sbaranes          #+#    #+#             */
/*   Updated: 2021/05/26 20:25:04 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	exec_absolute_path(t_data *data)
{
	if (!ft_strcmp(data->parsing.argument[1], "~"))
		chdir(data->path_home);
	else if (!ft_strcmp(data->parsing.argument[1], "--"))
		chdir(data->path_home);
}

static int	get_old_path(t_data *data)
{
	char	*path;

	path = NULL;
	path = getenv("OLDPWD");
	if (path == NULL)
		path = data->path_oldpwd;
	printf("test path = '%s'\n",path);
	return (chdir(path));
}

static int	check_cd_args(t_data *data, char *arg)
{
	DIR* rep;

	rep = opendir(arg);
	if (rep == NULL)
		return (FAILURE);
	if (!ft_strcmp(arg, ".."))
		return (get_old_path(data));
	else
		return (chdir(arg));
}

void	ft_cd(t_data *data)
{
	char	*home;

	home = NULL;
	if (!data->parsing.argument[1] || !ft_strcmp(data->parsing.argument[1], "~") || !ft_strcmp(data->parsing.argument[1], "--"))
	{
		home = getenv("HOME");
		if (!data->parsing.argument[1] && !home)
			return (ft_strerror("cd", NULL, "HOME not set\n"));
		else if (!data->parsing.argument[1])
			chdir(home);
		else
			exec_absolute_path(data);
	}
	else if (data->parsing.argument[1])
	{
		if (check_cd_args(data, data->parsing.argument[1]) == SUCCESS)
			return ;
		else
		{
			errno = 1;
			ft_strerror("cd", data->parsing.argument[1], "No such file or directory\n");
		}
	}
	errno = 0;
}
