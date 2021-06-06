/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:00:18 by sbaranes          #+#    #+#             */
/*   Updated: 2021/05/31 16:58:11 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

static int	check_cd_args(t_data *data, char *arg)
{
	DIR* rep;

	rep = opendir(arg);
	if (rep == NULL)
		return (FAILURE);
	else
	{
		set_oldpwd(data);
		chdir(arg);
		return (0);
	}
}

void	ft_cd(t_data *data)
{
	char	*home;
	char buf[256]; // a vire

	home = NULL;
	if(getcwd(buf, sizeof buf)!=NULL) puts(buf); // a vire
	if (!data->parsing.argument[1] || !ft_strcmp(data->parsing.argument[1], "~"))
	{
		home = getenv("HOME");
		if (!home && !data->parsing.argument[1])
			return (ft_strerror("cd", NULL, "HOME not set\n"));
		else
			chdir(home);
	}
	else if (data->parsing.argument[1])
	{
		if (check_cd_args(data, data->parsing.argument[1]) == SUCCESS)
		{
			if(getcwd(buf, sizeof buf)!=NULL) puts(buf); // a vire
			return ;
		}
		else
		{
			errno = 1;
			ft_strerror("cd", data->parsing.argument[1], "No such file or directory\n");
		}
	}
	errno = 0;
	
}
