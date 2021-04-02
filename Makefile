# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/20 13:45:18 by bmarilli          #+#    #+#              #
#    Updated: 2021/02/20 14:40:08 by bmarilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MINISHELL	= minishell

LIBFT = libft.a
LIB_DIR =  ./libft/
LIB_NAME =	./libft/libft.a

CC		= gcc

FLAGS	= -Wall -Wextra -Werror -g

HEADER	= ./includes
#HEADER_LIB = ./libft/includes
HEADERS = $(addprefix $(HEADER)/,libft.h get_next_line.h minishell.h)



DIR		= ./srcs/
DIR_BUILTINS = ./srcs/builtins/

F_NONE		= \033[37m
F_BOLD		= \033[1m
F_RED		= \033[31m
F_ORANGE	= \033[38m
F_YELLOW	= \033[33m
F_GREEN		= \033[32m
F_CYAN		= \033[36m
F_BLUE		= \033[34m


DIR_SH = $(addprefix $(DIR),minishell/)
SRC_SH = $(addprefix $(DIR_SH), ft_init_shell.c ft_print_shell.c)

DIR_ERR = $(addprefix $(DIR),error/)
SRC_ERR = $(addprefix $(DIR_ERR), ft_print_errno.c)

DIR_EXPORT = $(addprefix $(DIR_BUILTINS),export/)
SRC_EXPORT = $(addprefix $(DIR_EXPORT), ft_export.c  ft_print_export.c  ft_check_export.c  ft_envp_export.c)

DIR_ENV = $(addprefix $(DIR_BUILTINS),env/)
SRC_ENV = $(addprefix $(DIR_ENV), ft_env.c ft_find_envp.c )

DIR_UNSET = $(addprefix $(DIR_BUILTINS),unset/)
SRC_UNSET = $(addprefix $(DIR_UNSET), ft_unset.c ft_unset_envp_export.c  )

DIR_CD = $(addprefix $(DIR_BUILTINS),cd/)
SRC_CD = $(addprefix $(DIR_CD), ft_cd.c ft_oldpwd.c ft_new_pwd.c )

DIR_PWD = $(addprefix $(DIR_BUILTINS),pwd/)
SRC_PWD = $(addprefix $(DIR_PWD), ft_pwd.c)

DIR_ECHO = $(addprefix $(DIR_BUILTINS),echo/)
SRC_ECHO = $(addprefix $(DIR_ECHO), ft_echo.c)

DIR_EXIT = $(addprefix $(DIR_BUILTINS),exit/)
SRC_EXIT = $(addprefix $(DIR_EXIT), ft_exit.c)

DIR_CMD = $(addprefix $(DIR),command/)
SRC_CMD = $(addprefix $(DIR_CMD), ft_command.c  ft_dont_path.c ft_with_path.c  ft_fork_execve.c  ft_find_builtins.c ft_builtin.c)

DIR_REDIRECT = $(addprefix $(DIR),redirect/)
SRC_REDIRECT = $(addprefix $(DIR_REDIRECT), ft_change_fd.c ft_return_fd.c ft_is_original_fd.c)

DIR_PIPE = $(addprefix $(DIR),pipe/)
SRC_PIPE = $(addprefix $(DIR_PIPE), ft_init_cmd_pipe.c ft_return_standat_fd.c ft_all_pipe.c)

DIR_SIG = $(addprefix $(DIR),signal/)
SRC_SIG = $(addprefix $(DIR_SIG), ft_signal.c ft_signal_child_process.c)

DIR_PARSER = $(addprefix $(DIR),parser/)
SRC_PARSER = $(addprefix $(DIR_PARSER), boss_of_gang_parsers.c    gang_of_find_lens.c    ft_get_line.c   gang_of_join_find_check.c gang_of_mini_parsers.c   print_cmds.c)

SRCS = $(DIR)main.c\
		$(SRC_ERR)\
		$(SRC_SH)\
		$(SRC_EXPORT)\
		$(SRC_UNSET)\
		$(SRC_ENV)\
		$(SRC_CD)\
		$(SRC_PWD)\
		$(SRC_ECHO)\
		$(SRC_EXIT)\
		$(SRC_CMD)\
		$(SRC_REDIRECT)\
		$(SRC_PIPE)\
		$(SRC_SIG)\
		$(SRC_PARSER)

SRCS.O = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -I$(HEADER)  -c $< -o $@
	@echo "$(F_BLUE)Object files minishell in ready! $(F_NONE)"
#$(SRCS.O): %.o:%.c
#	$(CC) $(FLAGS) -I$(HEADER) -c $< -o $@
#	@echo "$(F_BLUE)Object files minishell in ready! $(F_NONE)"


all: $(LIB_NAME) $(NAME_MINISHELL)


$(LIB_NAME):
		@echo "$(F_YELLOW)START RUN Makefile in libft $(F_NONE)"
		@$(MAKE) -C $(LIB_DIR)
		rm includes/libft.h
		cp  libft/includes/libft.h includes/
		@echo "$(F_YELLOW)END RUN Makefile in libft $(F_NONE)"

$(NAME_MINISHELL): $(SRCS.O) $(HEADERS)
		@echo "$(F_CYAN)Compile minishell ...$(F_NONE)"
		$(CC) $(FLAGS)  -I$(HEADER)  $(SRCS.O) -L. $(LIB_NAME)	-o $(NAME_MINISHELL)
		@echo "$(F_GREEN)minishell is Ready! GOOD LUCK:) $(F_NONE)"


clean:

	rm -rf $(SRCS.O)
	@echo "$(F_GREEN)Object files minishell delete!$(F_NONE)"
fclean: clean
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME_MINISHELL)
	@echo "$(F_GREEN)Delete $(NAME_MINISHELL) FCleaned! $(F_NONE)"

re: fclean all

norm:
	norminette *.c *.h

code:
	@echo " ~~~~~~~~~~~~~~~~"
	@echo "$(F_BOLD)  * Make code, *"
	@echo "$(F_BOLD)   * not war! *"
	@echo "$(F_RED)    ..10101.."
	@echo "$(F_ORANGE)  01    1    10"
	@echo "$(F_YELLOW) 10     0     00"
	@echo "$(F_GREEN) 11   .010.   11"
	@echo "$(F_CYAN) 00 .01 1 01. 10"
	@echo "$(F_BLUE)  010   1   110"
	@echo "$(F_BLUE)    110110101$(F_NONE)"

.PHONY:     all clean fclean re bonus code
