/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniShell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:13:45 by sbaranes          #+#    #+#             */
/*   Updated: 2021/09/09 11:29:28 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Lib_perso/Includes/libft.h"
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <stdbool.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <sys/_pthread/_pthread_types.h>
# include <sys/_pthread/_pthread_t.h>

# include "../../../.brew/opt/readline/include/readline/readline.h"
# include "../../../.brew/opt/readline/include/readline/history.h"

# define SUCCESS 0
# define FAILURE 1

# define NO_FCT 0
# define FCT_EXIT 1
# define FCT_PWD 2
# define FCT_ENV 3
# define FCT_CD 4
# define FCT_UNSET 5
# define FCT_ECHO 6
# define FCT_EXPORT 7

typedef struct s_cmd	t_cmd;
typedef struct s_data	t_data;

t_data					g_data;

struct s_cmd
{
	char	*cmd;
	char	**argument;
	pid_t	pid;
	int		status;
	int		pipefd[2];
	t_cmd	*next;
	t_cmd	*prev;
};

typedef struct s_pars
{
	char	**argument;
	char	*token;
	char	type_cote;
	int		start;
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
	int		my_errno;
};

/*
**	main.c
*/
void	do_prompt(t_data *data);
void	recover_data(t_data *data);

/*
**	--- mandatory_function ---
*/
void	ft_cd(t_data *data);
void	ft_echo(t_data *data);
void	ft_env(t_data *data);
void	ft_export(t_data *data);
void	ft_pwd(t_data *data);
void	build_pwd(t_data *data);
void	ft_unset(t_data *data);
void	ft_exec_path(t_data *data);
void	ft_exec_builting_cmd(t_data *data, int code);

/*
**	--- parsing ---
*/
int		ft_token(t_data *data);
int		parsing_split(t_data *data);
int		prosses_dollar(t_data *data, int *start, int *i);

/*
**	--- utils ---
**	free.c
*/
void	free_tab_arg(t_data *data);
void	free_minishell(t_data *data);
void	free_double_etoile(char **str);

/*
**	ft_realloc.c
*/
void	ft_realloc_tab(t_data *data);
char	*ft_realloc(char *ptr, size_t new_size);

/*
**	function_env.c
*/
int		size_env(char **env);
char	**copy_env(char **env);
char	*my_getenv(t_data *data, char *str);
void	copy_env_add_one(t_data *data, char *new_elem);
void	copy_env_del_one(t_data *data, int index_elem_to_del);

/*
**	ft_bcopy.c
*/
void	ft_bcopy(const void *src, void *dest, size_t len);

/*
**	error.c
*/
void	ft_strerror(char *s1, char *s2, char *s3);
int		ft_strerror_export(char *s1, char *s2, char *s3);
int		ft_error_arg(char *str);
int		check_error(t_data *data);

/*
**	fonction_list.c
*/
void	big_cmdclear(t_data *data);
void	cmdclear(t_data *data);
t_cmd	*new_cmd_parsing(char **argument);
void	lstadd_back_cmd(t_cmd **alst, t_cmd *new);
void	set_up_prev(t_data *data);

/*
**	split_cmd_pipe.c
*/
void	split_cmd(t_data *data);
bool	check_if_have_pipe(t_data *data);

// split_cmd
void	cmd_check_cmd(t_data *data);
bool	check_if_have_cmd(t_data *data);
void	cmd_split_cmd(t_data *data);

/*
**	init.c
*/
void	init_ptr(void (*f[8])(t_data*));
void	init_structure(t_data *data);
void	init_start_loop(t_data *data);

/*
**	signal.c
*/
void	sig_ctrl_c(int signal);
void	sig_ctrl_bs(int signal);

/*
**	swap_fd.c
*/
void	replace_fd(t_data *data);
void	scan_fd(t_data *data);

/*
**	get_input.c
*/
int		scan_input(t_data *data);
void	get_input(t_data *data, char *name, char **new_arg, int nb_of_chevron);

/*
**	trim.c
*/
char	*strtrim_space(char *str);

/*
**	get_path.c
*/
int		get_path(t_data *data);
int		check_path(char *path);

/*
**	--- mandatoyu_function ---
**	utils_mandatory.c
*/
int		is_builting_cmd(t_data *data);
void	exe_cmd(t_data *data);
void	exe_pipe(t_data *data);

/*
**	ft_pwd.c
*/
void	set_oldpwd(t_data *data);

/*
**	pipe.c
*/
void	close_pipe(t_data *data);
void	close_all_pid(t_data *data);
void	child(t_data *data);

#endif
