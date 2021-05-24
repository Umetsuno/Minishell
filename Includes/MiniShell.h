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
# include <fcntl.h>
# include "struct.h"
# include "builtins_functions.h"
# include "get_next_line.h"

# define SUCCESS 0
# define FAILURE 0

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
char	*strtrim_space(char *str);

#endif
