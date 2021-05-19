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

# Lib_perso (.a)
.. = -L./Lib_perso -l

LIB = $(..)ftprintf

# chemin Sources
SA = Sources/

SRCS =	$(SA)main.c \
		$(SA)mandatory_function/ft_pwd.c

# normal Flags
CC = gcc

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -g3 -fsanitize=address

all:	compil $(NAME)

compil:
	@make -C $(LIB_PERSO)

%.o: %.c $(HEADER)
			@printf "\033[2K\r$(PURPLE)$<: $(CYAN)loading..$(RESET)"
			@gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER) $(LIB_PERSO)/libftprintf.a
		@gcc $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
		@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(ICONOK)Compiled [√]$(RESET)\n"

clean:
		@make clean -C $(LIB_PERSO)
		@$(RM) $(OBJS)

fclean:
		@make fclean -C $(LIB_PERSO)
		@$(RM) $(OBJS)
		@$(RM) $(NAME)
		@$(RM) Lib_perso/libftprintf.a
		@rm -rf *.dSYM
		@printf "$(CYAN)'$(NAME)', all .o & libftprintf.a $(RESET)has been $(RED)deleted. 🗑️\n"

shell:
		@gcc $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
		@./$(NAME)

norm:
		@norminette Includes Lib_perso Makefile Sources_checker Sources_push_swap

re : fclean all

help :
		@printf "\n$(GREY)Welcome to my Makefile.$(RESET)\n\n"
		@printf "$(YELLOW)all              $(RESET)$(WHITE) - run compilation of $(NAME)\n\n"
		@printf "$(YELLOW)exe              $(RESET)$(WHITE) - run gcc compilation with CFLAGS (-Wall -Wextra -Werror) and run $(NAME)\n\n"
		@printf "$(YELLOW)exeb             $(RESET)$(WHITE) - run gcc compilation with CFLAGS (-Wall -Wextra -Werror) and run $(NAME) + bonus\n\n"
		@printf "$(YELLOW)clean            $(RESET)$(WHITE) - delete all .o (OBJS) \n\n"
		@printf "$(YELLOW)fclean           $(RESET)$(WHITE) - delete all .o (OBJS) and $(NAME) \n\n"
		@printf "$(YELLOW)norm             $(RESET)$(WHITE) - run norminette v3 for all .c \n\n"
		@printf "$(YELLOW)re               $(RESET)$(WHITE) - do fclean and all\n\n"

.PHONY: all clean fclean re shell help
