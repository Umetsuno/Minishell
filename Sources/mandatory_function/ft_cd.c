/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:00:18 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/31 14:12:26 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

static int	check_cd_args(t_data *data, char *arg)
{
	DIR	*rep;

	rep = opendir(arg);
	if (rep == NULL)
		return (FAILURE);
	else
	{
		set_oldpwd(data);
		chdir(arg);
		build_pwd(data);
		errno = 0;
		closedir(rep);
		return (SUCCESS);
	}
}

void	ft_cd(t_data *data)
{
	char	*home;

	home = NULL;
	if (!data->cmd->argument[1] || !ft_strcmp(data->cmd->argument[1], "~"))
	{
		home = my_getenv(data, "HOME");
		if (!home && !data->cmd->argument[1])
			return (ft_strerror("cd", NULL, "HOME not set\n"));
		else
		{
			chdir(home);
			build_pwd(data);
		}
	}
	else if (data->cmd->argument[1])
	{
		if (check_cd_args(data, data->cmd->argument[1]) == SUCCESS)
			return ;
		else
		{
			ft_strerror("cd", data->cmd->argument[1], \
				"No such file or directory\n");
			errno = 1;
		}
	}
}
