# Colors
GREY = \033[4;34m
RED = \033[1;31m
GREEN = \033[3;32m
YELLOW = \033[2;49;33m
BLUE = \033[4;34m
BLUEE = \033[3;34m
PURPLE = \033[3;35m
CYAN = \033[3;36m
RESET = \033[0m
ICONOK = \033[1;32m
ICONKO = \033[1;31m
CO_DELET = \033[3;31m
CO_A_OUT = \033[96m
WHITE = \033[1;49;97m

# Executable
NAME = MiniShell

# Include
HEADER = ./Includes/MiniShell.h

# Libf_perso
LIB_PERSO = ./Lib_perso

LIB_READLINE = ./readline

# Lib_perso (.a)
LIBP = -L./Lib_perso -lftprintf

LIBR = -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include

# chemin Sources
SA = Sources/
SM = Sources/mandatory_function/
SU = Sources/utils/
SP = Sources/parsing/

SRCS =	$(SA)main.c \
		$(SM)ft_pwd.c \
		$(SM)ft_cd.c \
		$(SM)ft_echo.c \
		$(SM)ft_env.c \
		$(SM)ft_export.c \
		$(SM)ft_exec.c \
		$(SM)ft_unset.c \
		$(SU)trim.c \
		$(SU)get_path.c \
		$(SU)free.c \
		$(SU)init.c \
		$(SU)function_env.c \
		$(SU)ft_strerror.c \
		$(SP)parser.c

# normal Flags
CC = gcc

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra #-g3 -fsanitize=address

all:	compil $(NAME)

compil:
	@make -C $(LIB_PERSO)

%.o:	%.c $(HEADER)
	@printf "\033[2K\r$(PURPLE)$<: $(CYAN)loading..$(RESET)"
	@gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER) $(LIB_PERSO)/libftprintf.a
	@gcc $(LIBR) $(CFLAGS) $(SRCS) $(LIBP) -o $(NAME)
	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(ICONOK)Compiled [√]$(RESET)\n"

clean:
	@make clean -C $(LIB_PERSO)
	@$(RM) $(OBJS)

fclean:	clean
	@make fclean -C $(LIB_PERSO)
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@$(RM) Lib_perso/libftprintf.a
	@rm -rf *.dSYM
	@printf "$(CYAN)'$(NAME)', all .o & libftprintf.a $(RESET)has been $(RED)deleted. 🗑️\n"

shell:
	@gcc $(LIBR) $(CFLAGS) $(SRCS) $(LIBP) -o $(NAME)
	@./$(NAME)

norm:
	@norminette Includes Lib_perso Makefile Sources/*.c Sources/mandatory_function/*.c

re : fclean all

.PHONY: all clean fclean re shell
