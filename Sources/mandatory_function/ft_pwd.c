/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:49:27 by sbaranes          #+#    #+#             */
/*   Updated: 2021/05/18 15:14:03 by sbaranes         ###   ########lyon.fr   */
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
