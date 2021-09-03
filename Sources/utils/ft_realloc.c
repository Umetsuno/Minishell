/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oghma <fabien@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:05:01 by oghma             #+#    #+#             */
/*   Updated: 2021/09/03 20:03:45 by oghma            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

char	**ft_realloc_tab(char **tab, char *n)
{
	int		i;
	int		j;
	char	**new_tab;

	j = 0;
	new_tab = NULL;
	i = size_env(tab);
	new_tab = malloc(sizeof(char *) * (i + 2));
	while (j < i)
	{
		new_tab[j] = ft_strdup(tab[j]);
		j++;
	}
	new_tab[j] = ft_strdup(n);
	j++;
	new_tab[j] = NULL;
	free_double_etoile(tab);
	return (new_tab);
}

// char	*ft_realloc(char *ptr, size_t new_size)
// {
// 	size_t	current_size;
// 	char	*new_ptr;

// 	if (ptr == 0)
// 		return (malloc(new_size));
// 	current_size = ft_strlen(ptr);
// 	if (new_size <= current_size)
// 		return (ptr);
// 	new_ptr = malloc(new_size);
// 	ft_bcopy(ptr, new_ptr, (int)current_size);
// 	free(ptr);
// 	return(new_ptr);
// }

char	*ft_realloc(char *ptr, size_t new_size)
{
	size_t	current_size;
	char	*new_ptr;

	new_ptr = 0;
	current_size = 0;
	if (ptr == 0)
		return (malloc(new_size)); // ou return (NULL); a tester. Idealement return malloc est mieux
	new_ptr = (char *)ft_calloc((ft_strlen(ptr) + new_size + 1), sizeof(*new_ptr));
	if (!new_ptr)
		return (NULL);
	bcopy(ptr, new_ptr, (int)current_size);
	//while (current_size < (ft_ptrlen(ptr) + new_size) && ptr[current_size])
	//{
	//	new_ptr[current_size] = ptr[current_size];
	//	current_size++;
	//}
	new_ptr[current_size] = '\0';
	free(ptr);
	return (new_ptr);
}
