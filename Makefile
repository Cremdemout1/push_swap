# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohan <yohan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 15:26:22 by ycantin           #+#    #+#              #
#    Updated: 2024/05/24 09:59:19 by yohan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a
NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -I -g #-fsanitize=address,undefined
RM = rm -f

#COM_DIR = push rev_rotate rotate swap
SRC = 	commands/push.c \
		commands/rev_rotate.c \
		commands/rotate.c \
		commands/swap.c \
		median/find_median.c \
		median/radix_sort.c \
		errors/error_handling.c \
		errors/frees.c \
		initiation.c \
		ps_utils.c \
		new_sort.c \
		move_calc.c \
		cost.c \
		main.c

all: $(NAME)

$(LIBFT):
	@make -C ./libft/

$(NAME): $(LIBFT) $(SRC)
	@$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)

clean: 
	@$(RM) $(OBJ)
	@make clean -C ./libft/

fclean:	clean 
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re:	fclean $(NAME) 
