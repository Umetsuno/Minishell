/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:58:30 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/08 15:00:02 by sbaranes         ###   ########lyon.fr   */
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
	}
	free(str);
	str = NULL;
}

static void	lstclear(t_env **lst)
{
	t_env	*p;

	while (*lst)
	{
		p = (*lst)->next;
		free(lst);
		(*lst) = p;
	}
}

void	free_minishell(t_data *data)
{
	if (data->line)
		free(data->line);
	if (data->path_oldpwd)
		free(data->path_oldpwd);
	free(data->path_home);
	lstclear(data->env);
	exit(0);
}
