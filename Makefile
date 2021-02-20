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

NAME	= minishell

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

HEADER	= ./includes
HEADERS = $(addprefix $(HEADER)/,libft.h get_next_line.h minishell.h)

F_NONE		= \033[37m
F_BOLD		= \033[1m
F_RED		= \033[31m
F_ORANGE	= \033[38m
F_YELLOW	= \033[33m
F_GREEN		= \033[32m
F_CYAN		= \033[36m
F_BLUE		= \033[34m


SRCS.O = $(SRCS:.c=.o)

$(NAME):	$(SRCS.O) $(HEADERS)


$(SRCS.O): %.o:%.c
	$(CC) $(FLAGS) -I$(HEADER) -c $< -o $@
	@echo "$(F_BLUE)Object files minishell in ready! $(F_NONE)"


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
