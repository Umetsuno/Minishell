/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:17:08 by faherrau          #+#    #+#             */
/*   Updated: 2021/08/12 15:43:14 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "MiniShell.h"

typedef struct s_cmd	t_cmd;
typedef struct s_data	t_data;

struct s_cmd
{
	char	*cmd;
	char	**argument;
	int		pipefd[2];
	pid_t	pid;
	t_cmd	*next;
	t_cmd	*prev;
};

typedef struct s_pars
{
	char	**argument;
}t_pars;

struct s_data
{
	t_pars	parseur;
	t_cmd	*cmd;
	t_cmd	*save_cmd;
	t_cmd	*all_cmd;
	t_cmd	*save_all_cmd;
	void	(*f[8])(t_data*);
	char	*line;
	char	*path;
	char	**env;
	char	**path_split;
	char	*path_pwd;
	char	*path_home;
	char	*path_oldpwd;
	int		index;
	int		temp_fd;
	int		save_fd;
	bool	error;
	bool	in_cmd;
	bool	nonewline;
	bool	del_temp;
	bool	already;
	bool	check_pipe;
};

#endif
