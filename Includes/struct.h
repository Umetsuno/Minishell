/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:17:08 by faherrau          #+#    #+#             */
/*   Updated: 2021/06/28 15:12:16 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "MiniShell.h"

typedef struct s_data	t_data;

typedef struct s_parsing
{
	char	*line;
	char	*cmd;
	char	**argument;
}t_parsing;

struct s_data
{
	t_parsing	parsing;
	void		(*f[8])(t_data*);
	char		*line;
	char		*path;
	char		**env;
	char		**path_split;
	char		*path_pwd;
	char		*path_home;
	char		*path_oldpwd;
	int			index;
	int			fd;
	bool		in_cmd;
};



#endif
