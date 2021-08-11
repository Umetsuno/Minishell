/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:41:10 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/11 15:18:46 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	cmdclear(t_data *data)
{
	t_cmd	*p;

	while (data->all_cmd)
	{
		p = data->all_cmd->next;
		free(data->all_cmd->cmd);
		free_double_etoile(data->all_cmd->argument);
		free(data->all_cmd);
		data->all_cmd = p;
	}
}

t_cmd	*new_cmd_parsing(char **argument)
{
	t_cmd	*element;

	element = malloc(sizeof(t_cmd));
	if (!element)
		return (NULL);
	element->argument = argument;
	element->cmd = ft_strdup(argument[0]);
	element->next = NULL;
	return (element);
}

void	lstadd_back_cmd(t_cmd **alst, t_cmd *new)
{
	t_cmd	*p;

	p = *alst;
	if (!alst)
		return ;
	if (!*alst)
		*alst = new;
	else if (p)
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}
