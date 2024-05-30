# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 15:26:22 by ycantin           #+#    #+#              #
#    Updated: 2024/05/30 13:52:55 by ycantin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a
NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -I -g
RM = rm -f

SRC = 	commands/push.c \
		commands/rev_rotate.c \
		commands/rotate.c \
		commands/swap.c \
		errors/error_handling.c \
		errors/frees.c \
		initiation.c \
		ps_utils.c \
		data_initiation/node_assignment_utils.c \
		data_initiation/node_data_assignment.c \
		move_logic.c \
		sort.c \
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
