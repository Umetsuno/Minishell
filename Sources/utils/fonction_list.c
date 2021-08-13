/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:41:10 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/12 18:51:40 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	big_cmdclear(t_data *data)
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
	free(data->cmd_unique);
}

void	cmdclear(t_data *data)
{
	t_cmd	*p;

	while (data->cmd_unique)
	{
		p = data->cmd_unique->next;
		free(data->cmd_unique->cmd);
		free_double_etoile(data->cmd_unique->argument);
		free(data->cmd_unique);
		data->cmd_unique = p;
	}
	free(data->cmd_unique);
}

t_cmd	*new_cmd_parsing(char **argument)
{
	t_cmd	*element;

	element = malloc(sizeof(t_cmd));
	if (!element)
		return (NULL);
	element->argument = copy_env(argument);
	element->cmd = ft_strdup(argument[0]);
	element->next = NULL;
	element->prev = NULL;
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

void	set_up_prev(t_data *data)
{
	t_cmd	*elem;
	t_cmd	*temp;
	int		i;

	i = 0;
	elem = data->cmd_unique;
	while (elem)
	{
		if (i != 0)
			elem->prev = temp;
		temp = elem;
		elem = elem->next;
		i++;
	}
}

t_cmd	*lstget_last(t_data *data)
{
	t_cmd *cursor;

	cursor = data->cmd_unique;
	while (cursor->next)
	{
		cursor = cursor->next;
	}
	return (cursor);
}
