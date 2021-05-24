/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:12:37 by faherrau          #+#    #+#             */
/*   Updated: 2021/05/24 18:46:21 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	ft_pwd(t_data *data)
{
	char str[200];

	data->index = 0;
	if (getcwd(str, 200) == NULL)
		errno = 1;
	else
	{
		printf("%s\n", str);
		errno = 0;
	}
}
