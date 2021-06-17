/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:58:30 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/17 10:16:26 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	free_double_etoile(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	free_minishell(t_data *data)
{
	if (data->line)
		free(data->line);
	if (data->path_oldpwd)
		free(data->path_oldpwd);
	if (data->path_home)
		free(data->path_home);
	printf("exit\n");
	exit(0);
}
