/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:17:08 by faherrau          #+#    #+#             */
/*   Updated: 2021/06/08 14:58:14 by sbaranes         ###   ########lyon.fr   */
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
	char	**argument;
}t_parsing;

typedef	struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}t_env;

struct s_data
{
	t_parsing	parsing;
	t_env		*env;
	void		(*f[8])(t_data*);
	char		*line;
	char		*path;
	char		**path_split;
	char		**env;
	char		*path_pwd;
	char		*path_home;
	char		*path_oldpwd;
	int			index;
};



#endif
