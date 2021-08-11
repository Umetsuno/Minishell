/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:41:10 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/11 13:24:01 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	cmdclear_parsing(t_data *data)
{
	t_parsing	*p;

	while (data->all_cmd)
	{
		p = data->all_cmd->next;
		free(data->all_cmd->cmd);
		free_double_etoile(data->all_cmd->argument);
		free(data->all_cmd);
		data->all_cmd = p;
	}
}

t_parsing	*new_cmd_parsing(char **argument)
{
	t_parsing	*element;

	element = malloc(sizeof(t_parsing));
	if (!element)
		return (NULL);
	element->argument = argument;
	element->cmd = ft_strdup(argument[0]);
	element->next = NULL;
	return (element);
}
