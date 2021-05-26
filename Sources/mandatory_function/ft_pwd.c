/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:12:37 by faherrau          #+#    #+#             */
/*   Updated: 2021/05/26 19:36:22 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	build_pwd(t_data *data)
{
	data->path_pwd = getenv("PWD");
	if (data->path_pwd == NULL)
	{
		data->path_pwd = ft_calloc(sizeof(char), PATH_MAX + 1);
		if (data->path_pwd == NULL)
			return ;
		if (getcwd(data->path_pwd, (PATH_MAX + 1)) == NULL)
		{
			printf("Error (getcwd) : %s\n", strerror(errno));
			errno = 132;
		}
	}
	puts(data->path_pwd);
}

void	ft_pwd(t_data *data)
{
	printf("%s\n", &data->path_pwd[4]);
	errno = 0;
}
