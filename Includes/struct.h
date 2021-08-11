/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:17:08 by faherrau          #+#    #+#             */
/*   Updated: 2021/08/11 13:20:36 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "MiniShell.h"

typedef struct s_data		t_data;
typedef struct s_parsing	t_parsing;

struct s_parsing
{
	char		*cmd;
	char		**argument;
	t_parsing	*next;
};

typedef struct s_pipe
{
	bool		pipe;
	int			*pipefd;
}t_pipe;

struct s_data
{
	t_parsing	*parsing;
	t_parsing	*all_cmd;
	t_pipe		p;
	void		(*f[8])(t_data*);
	char		*line;
	char		*path;
	char		**env;
	char		**path_split;
	char		*path_pwd;
	char		*path_home;
	char		*path_oldpwd;
	char		*last_input;
	int			index;
	int			temp_fd;
	int			save_fd;
	bool		error;
	bool		in_cmd;
	bool		nonewline;
	bool		del_temp;
	bool		already;
};

#endif
