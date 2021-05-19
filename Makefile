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
HEADER = ./includes/minishell.h

# Libf_perso
LBFT = ./best-libft

# LBFT (.a)
.. = -L./best-libft -l

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
	@make -C $(LBFT)

%.o: %.c $(HEADER)
			@printf "\033[2K\r$(PURPLE)$<: $(CYAN)loading..$(RESET)"
			@gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER) $(LBFT)/libftprintf.a
		@gcc $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
		@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(ICONOK)Compiled [√]$(RESET)\n"

clean:
		@make clean -C $(LBFT)
		@$(RM) $(OBJS)

fclean:
		@make fclean -C $(LBFT)
		@$(RM) $(OBJS)
		@$(RM) $(NAME)
		@rm -rf *.dSYM
		@printf "$(CYAN)'$(NAME)', all .o & libftprintf.a $(RESET)has been $(RED)deleted. 🗑️\n"

shell:
		@gcc $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
		@./$(NAME)

norm:
		@norminette includes best-libft Makefile

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



# -----

# NAME			=	minishell

# BLACK			=	\033[0;30m
# RED				=	\033[0;31m
# GREEN			=	\033[0;32m
# ORANGE			=	\033[0;33m
# BLUE			=	\033[0;34m
# PURPLE			=	\033[0;35m
# CYAN			=	\033[0;36m
# LIGHT_GRAY		=	\033[0;37m
# DARK_GRAY		=	\033[1;30m
# LIGHT_RED		=	\033[1;31m
# LIGHT_GREEN		=	\033[1;32m
# YELLOW			=	\033[1;33m
# LIGHT_BLUE		=	\033[1;34m
# LIGHT_PURPLE	=	\033[1;35m
# LIGHT_CYAN		=	\033[1;36m
# WHITE			=	\033[1;37m
# NO_COLOR		=	\033[0m

# -include sources.mk
# -include includes.mk

# INCLUDES_PATH	=	./includes
# LIBFT_PATH		=	./libft

# GCC				=	gcc
# FLAGS			=	-Wall -Wextra -Werror -O3 -Ofast -flto -march=native -ffast-math
# OBJECTS			=	$(SOURCES:.c=.o)
# RM				=	rm -f

# all:	$(NAME)

# $(LIBFT_PATH)/libft.a:
# 	$(MAKE) -C $(LIBFT_PATH) all

# %.o:	%.c $(LIBFT_PATH)/libft.a $(MLX_PATH)/libmlx.a $(INCLUDES)
# 	@$(GCC) $(FLAGS) -I $(INCLUDES_PATH) -c $< -o $@
# 	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(PURPLE)$<$(RESET)"

# $(NAME):	$(LIBFT_PATH)/libft.a $(INCLUDES) $(OBJECTS)
# 	@$(GCC) -L mlx -l mlx -framework OpenGL -framework AppKit $(LIBFT_PATH)/libft.a $(FLAGS) -I $(INCLUDES_PATH) $(OBJECTS) -o $(NAME)
# 	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(GREEN)Compiled [√]$(RESET)\n"

# oclean:
# 	@printf "$(BLUE)$(NAME): $(LIGHT_RED)Cleaning all .o in project.\n$(RESET)"
# 	@$(RM) $(OBJECTS)

# clean: oclean
# 	@$(MAKE) -C $(LIBFT_PATH) clean
# 	@printf "$(BLUE)libmlx.a: $(LIGHT_RED)Cleaning all .o in libmlx.\n$(RESET)"
# 	@$(MAKE) -C $(MLX_PATH) clean

# fclean:
# 	@$(MAKE) -C $(LIBFT_PATH) fclean
# 	@printf "$(BLUE)libmlx.a: $(LIGHT_RED)Cleaning all .o in libmlx.\n$(RESET)"
# 	@printf "$(BLUE)libmlx.a: $(RED)Cleaning compiled library libmlx.\n$(RESET)"
# 	@$(MAKE) -C $(MLX_PATH) clean
# 	@printf "$(BLUE)$(NAME): $(RED)Cleaning compiled program $(NAME).\n$(RESET)"
# 	@$(RM) $(NAME)

# re:	fclean all

# gmk:
# 	@printf "$(BLUE)$(NAME): $(GREEN)Generating Makefile includes.\n$(RESET)"
# 	@find sources -name '*.c' | sed 's/^/SOURCES += /' > sources.mk
# 	@find includes -name '*.h' | sed 's/^/INCLUDES += /' > includes.mk

# norminette: oclean
# 	@printf "$(BLUE)$(NAME): $(GREEN)norminette -> sources\n$(RESET)"
# 	@norminette sources
# 	@echo " "
# 	@printf "$(BLUE)$(NAME): $(GREEN)norminette -> includes\n$(RESET)"
# 	@norminette includes

# end:
# 	@make fclean
# 	@make gmk
# 	@make all
# 	@make norminette
# 	@make fclean
# 	@printf "$(BLUE)$(NAME): $(LIGHT_CYAN)Prepared to be pushed.\n$(RESET)"

# .PHONY:	all oclean clean fclean re gmk norminette end
