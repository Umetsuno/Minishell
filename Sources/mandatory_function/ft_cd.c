/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:00:18 by sbaranes          #+#    #+#             */
/*   Updated: 2021/05/26 20:25:04 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	ft_cd(t_data *data)
{
	char	*home;

	home = NULL;
	if (data->parsing.argument[0] && data->parsing.argument[1] && data->parsing.argument[2])
		ft_puterrord("bash: cd: HOME not set\n",);
	if (!data->parsing.argument[1] || !ft_strcmp(data->parsing.argument[1], "~") || !ft_strcmp(data->parsing.argument[1], "--"))
	{
		if (!(home = get_env("HOME")))
		{
			ft_putstr_fd("bash: cd: HOME not set\n", 2);
			return ;
		}
	}
	else if (data->parsing.argument[1])
	{
		if (do_cd(data, data->parsing.argument[1]) == SUCCESS)
			return ;
		else
			ft_puterrord("bash: cd: HOME not set\n",);
	}
}
