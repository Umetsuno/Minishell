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
# include "struct.h"
# include <signal.h>
# include <dirent.h>
# include <sys/_pthread/_pthread_types.h>
# include <sys/_pthread/_pthread_t.h>
# include "builtins_functions.h"
# include "env.h"
# include "parsing.h"

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

void	test(t_data *data);
t_data g_data;
/*
**	main.c
*/
void	do_prompt(t_data *data);


/*
**	--- utils ---
**	free.c
*/
void	free_minishell(t_data *data);
void	free_double_etoile(char **str);
void	kill_lst(t_cmd *cmd);
/*
**	errro.c
*/
void	ft_strerror(char *s1, char *s2, char *s3);
int		ft_strerror_export(char *s1, char *s2, char *s3);
int		ft_error_arg(char *str);

/*
**	fonction_list.c
*/
void	cmdclear(t_data *data);
t_cmd	*new_cmd_parsing(char **argument);
void	lstadd_back_cmd(t_cmd **alst, t_cmd *new);
void	set_up_prev(t_data *data);
t_cmd	*lstget_last(t_data *data);

/*
**	split_cmd.c
*/
void	split_cmd(t_data *data);
bool	check_if_have_pipe(t_data *data);

/*
**	init.c
*/
void	init_ptr(void (*f[8])(t_data*));
void	init_structure(t_data *data, char **av);
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
int		init_pipe(t_data *data);
void	child(t_data *data);

#endif
