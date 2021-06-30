/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:22:11 by sbaranes          #+#    #+#             */
/*   Updated: 2021/06/30 15:16:53 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/MiniShell.h"

void	Create_file_to_write(t_data *data, char *name, int code)
{
	int	fd;
	if (code == 1)
		fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else
		fd = open(name, O_CREAT | O_WRONLY, 0644);
	if (data->fd != 1 && data->fd != fd)
		close(data->fd);
	data->fd = fd;
}

void	write_in_file(t_data *data, char *output)
{
	write(data->fd, &output, ft_strlen(output));
}
