/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:55:53 by sbaranes          #+#    #+#             */
/*   Updated: 2021/03/24 15:47:06 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lol;

	lol = malloc(sizeof(t_list));
	if (!lol)
		return (NULL);
	(*lol).content = content;
	(*lol).next = NULL;
	return (lol);
}
