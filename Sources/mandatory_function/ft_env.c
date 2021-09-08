/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:06:21 by sbaranes          #+#    #+#             */
/*   Updated: 2021/08/31 14:10:36 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

char	*add_equal(char *var)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = ft_strlen(var);
	str = ft_calloc(size + 2, sizeof(char));
	while (var[i])
	{
		str[i] = var[i];
		i++;
	}
	str[i++] = '=';
	str[i] = 0;
	return (str);
}

char	*my_getenv(t_data *data, char *var)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	str = add_equal(var);
	size = ft_strlen(str);
	if (!ft_strcmp(str, "?="))
	{
		free(str);
		return (ft_itoa(data->my_errno));
	}
	while (data->env[i])
	{
		if (!ft_strncmp(data->env[i], str, size))
		{
			free(str);
			return (ft_strdup(&data->env[i][size]));
		}
		i++;
	}
	return (NULL);
}

void	ft_env(t_data *data)
{
	int	index;

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
