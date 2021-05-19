#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
#include <limits.h>
# include <fcntl.h>
# include "../Lib_perso/Includes/libft.h"

typedef struct s_data t_data;
typedef enum e_code		t_code;

typedef struct s_parsing
{
	char *line;
	char *command;
	char *flag;
	char *argument;
}t_parsing;

struct s_data
{
	int i;
	char *line;
	t_parsing parsing;
};

enum e_code{
	SUCCESS,
	FAIL,
};
/*
**	Fonctions Principal
*/


/*
**	Fonctions demander
*/
int	ft_pwd(void);

#endif
