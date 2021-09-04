/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:58:30 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/12 16:36:58 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	free_tab_arg(t_data *data)
{
	int	i;

	i = 0;
	if (!data->parseur.argument)
		return ;
	while (data->parseur.argument[i])
	{
		if (data->parseur.argument[i])
		{
			free(data->parseur.argument[i]);
			data->parseur.argument[i] = NULL;
		}
		i++;
	}
	free(data->parseur.argument);
	data->parseur.argument = NULL;
}

void	free_double_etoile(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i])
		{
			free(str[i]);
			str[i] = NULL;
		}
		i++;
	}
	if (str)
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
	cmdclear(data);
	big_cmdclear(data);
	printf("exit\n");
	exit(EXIT_SUCCESS);
}
