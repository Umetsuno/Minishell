/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:06:21 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/15 18:44:00 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

char	*my_getenv(t_data *data, char *str)
{
	int	i;
	int	size_str;

	i = 0;
	size_str = ft_strlen(str);
	while (data->env[i])
	{
		if (!ft_strncmp(data->env[i], str, size_str))
			return	(&data->env[i][size_str]);
		i++;
	}
	return (NULL);
}

void	ft_env(t_data *data)
{
	int index;

	index = 0;
	if (data->env == NULL)
		errno = 127;
	else
	{
		while (data->env[index])
		{
			if (ft_strchr(data->env[index], '=') != NULL)
				printf("%s\n", data->env[index]);
			index++;
		}
		errno = 0;
	}
}
