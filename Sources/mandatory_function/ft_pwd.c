/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:12:37 by faherrau          #+#    #+#             */
/*   Updated: 2021/06/14 20:10:49 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	build_pwd(t_data *data)
{
	if (data->path_pwd)
		free(data->path_pwd);
	data->path_pwd = ft_calloc(sizeof(char), PATH_MAX + 1);
	if (data->path_pwd == NULL)
		return ;
	if (getcwd(data->path_pwd, (PATH_MAX + 1)) == NULL)
	{
		printf("Error (getcwd) : %s\n", strerror(errno));
		errno = 132;
	}
}

void	set_oldpwd(t_data *data)
{
	if (data->path_oldpwd)
		free(data->path_oldpwd);
	data->path_oldpwd = ft_strdup(data->path_pwd);
}

void	ft_pwd(t_data *data)
{
	printf("%s\n", data->path_pwd);
	errno = 0;
}
