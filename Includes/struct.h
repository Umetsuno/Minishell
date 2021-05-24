/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:17:08 by faherrau          #+#    #+#             */
/*   Updated: 2021/05/24 18:45:30 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "MiniShell.h"

typedef struct s_data t_data;

typedef struct s_parsing
{
	char	*line;
	char	*command;
	char	*flag;
	char	*argument;
}t_parsing;

struct s_data
{
	t_parsing	parsing;
	void		(*f[8])(t_data*);
	char		*line;
	char		**env;
	int			index;
};

#endif
