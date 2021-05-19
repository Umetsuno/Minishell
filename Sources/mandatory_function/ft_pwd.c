/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faherrau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:12:37 by faherrau          #+#    #+#             */
/*   Updated: 2021/05/19 16:12:39 by faherrau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../Includes/MiniShell.h"

int	ft_pwd(void)
{
	char str[200];

	if (getcwd(str, 200) == NULL)
		return (EXIT_FAILURE);
	puts(str);
	return EXIT_SUCCESS;
}
