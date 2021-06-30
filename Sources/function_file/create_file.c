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

void	Create_file(t_data *data, char *name)
{
	int	fd;

	fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (data->fd != 1 && data->fd != fd)
		close(data->fd);
	data->fd = fd;
}

void	Create_file_or_write_at_end(t_data *data, char *name, char *arg)
{
	int	fd;

	fd = open(name, O_CREAT | O_WRONLY, 0644);
	if (data->fd != 1 && data->fd != fd)
		close(data->fd);
	data->fd = fd;
	write(data->fd, arg, ft_strlen(arg));
}

void	write_in(t_data *data)
{

}

int main(void)
{
	g_data.fd = 1;

	Create_file(&g_data, "hello");
	write_in(&g_data);

	return 0;
}
