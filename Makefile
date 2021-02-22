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

FLAGS	= -Wall -Wextra -Werror

HEADER	= ./includes
HEADERS = $(addprefix $(HEADER)/,libft.h get_next_line.h minishell.h)

DIR		= ./srcs/

F_NONE		= \033[37m
F_BOLD		= \033[1m
F_RED		= \033[31m
F_ORANGE	= \033[38m
F_YELLOW	= \033[33m
F_GREEN		= \033[32m
F_CYAN		= \033[36m
F_BLUE		= \033[34m

SRCS = $(DIR)main.c

SRCS.O = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -I$(HEADER) -c $< -o $@
	@echo "$(F_BLUE)Object files minishell in ready! $(F_NONE)"
#$(SRCS.O): %.o:%.c
#	$(CC) $(FLAGS) -I$(HEADER) -c $< -o $@
#	@echo "$(F_BLUE)Object files minishell in ready! $(F_NONE)"


all: $(LIB_NAME) $(NAME_MINISHELL)


$(LIB_NAME):
		@echo "$(F_YELLOW)START RUN Makefile in libft $(F_NONE)"
		@$(MAKE) -C $(LIB_DIR)
		@echo "$(F_YELLOW)END RUN Makefile in libft $(F_NONE)"

$(NAME_MINISHELL): $(SRCS.O) $(HEADERS)
		@echo "$(F_CYAN)Compile minishell ...$(F_NONE)"
		$(CC) $(FLAGS)  -I$(HEADER) $(SRCS.O) -L. $(LIB_NAME)	-o $(NAME_MINISHELL)
		@echo "$(F_GREEN)minishell is Ready! GOOD LUCK:) $(F_NONE)"


clean:

	rm -rf $(SRCS.O)
	@echo "$(F_GREEN)Object files delete!$(F_NONE)"
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
	@echo "$(F_ORANGE)  01   1   011"
	@echo "$(F_YELLOW) 10     0     00"
	@echo "$(F_GREEN) 11   .010.   11"
	@echo "$(F_CYAN) 00 .01 1 01. 10"
	@echo "$(F_BLUE) 010   1   110"
	@echo "$(F_BLUE)   11011010**$(F_NONE)"

.PHONY:     all clean fclean re bonus code
