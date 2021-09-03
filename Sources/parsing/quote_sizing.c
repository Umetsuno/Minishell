/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_sizing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:16:57 by oghma             #+#    #+#             */
/*   Updated: 2021/09/03 17:51:09 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

/* Cette fonction prend une string en argument.
Elle renvoie un int représentant l'index de la deuxième occurence du premier caractere de la string ou une erreur (-1)*/
int		quote_sizing(char *str)
{
	int		i;

	i = 1;
	while (str[i])
    {
        if (str[i] == str[0])
            return (i);
		i++;
    }
	return (-1);
}
