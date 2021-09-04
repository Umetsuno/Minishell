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

	while (data->save_all_cmd)
	{
		p = data->save_all_cmd->next;
		if (data->save_all_cmd->cmd)
			free(data->save_all_cmd->cmd);
		free_double_etoile(data->save_all_cmd->argument);
		free(data->save_all_cmd);
		data->save_all_cmd = p;
	}
	free(data->save_all_cmd);
	data->save_all_cmd = NULL;
	data->all_cmd = NULL;
}

void	cmdclear(t_data *data)
{
	t_cmd	*p;

	while (data->save_cmd)
	{
		p = data->save_cmd->next;
		free(data->save_cmd->cmd);
		free_double_etoile(data->save_cmd->argument);
		free(data->save_cmd);
		data->save_cmd = p;
	}
	free(data->save_cmd);
	data->cmd = NULL;
}

t_cmd	*new_cmd_parsing(char **argument)
{
	t_cmd	*element;

	element = ft_calloc(1, sizeof(t_cmd));
	if (!element)
		return (NULL);
	element->cmd = ft_strdup(argument[0]);
	element->argument = copy_env(argument);
	element->status = 0;
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
	elem = data->cmd;
	while (elem)
	{
		if (i != 0)
			elem->prev = temp;
		temp = elem;
		elem = elem->next;
		i++;
	}
}
