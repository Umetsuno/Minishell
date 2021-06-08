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
# include "get_next_line.h"

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

/*
**	?? Main functions ??
*/
void	free_minishell(t_data *data);

void	init_structure(t_data *data, char **av, char **env);
void	init_ptr(void (*f[8])(t_data*));

char	*strtrim_space(char *str);
int		get_path(t_data *data);
void	ft_strerror(char *s1, char *s2, char *s3);
int		ft_error_arg(char *str);
void	free_double_etoile(char **str);
void	set_oldpwd(t_data *data);

void	print_lst(t_data *data);
t_env	*new_lst(char *name, char *value);
void	lstadd_back(t_env **alst, t_env *new);
void	lstclear(t_env **lst);

#endif
