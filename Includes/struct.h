/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:17:08 by faherrau          #+#    #+#             */
/*   Updated: 2021/05/26 19:30:32 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "MiniShell.h"

typedef struct s_data t_data;

typedef struct s_parsing
{
	char	*line;
	char	*cmd;
	char	*flag;
	char	**argument;
}t_parsing;

struct s_data
{
	t_parsing	parsing;
	void		(*f[8])(t_data*);
	char		*line;
	char		*path;
	char		**path_split;
	char		**env;
	char		*path_pwd;
	int			index;
};

#endif
