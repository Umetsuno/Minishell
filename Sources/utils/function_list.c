/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:51:19 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/08 14:59:19 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

t_env	*new_lst(char *name, char *value)
{
	t_env	*elem;

	elem = wrmalloc(sizeof(t_env));
	if (!elem)
		return (NULL);
	elem->name = name;
	elem->value = value;
	elem->next = NULL;
	return (elem);
}

void	lstadd_back(t_env **alst, t_env *new)
{
	t_env	*p;

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

void	print_lst(t_data *data)
{
	t_env	*p;

	p = data->env;
	while (p)
	{
		printf("%s=%s\n", p->name, p->value);
		p = p->next;
	}
	ft_putstr("\n");
}
