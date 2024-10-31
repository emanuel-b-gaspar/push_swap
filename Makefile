# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebunga-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 11:54:39 by ebunga-g          #+#    #+#              #
#    Updated: 2024/10/29 14:14:04 by ebunga-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		= -Wall -Wextra -Werror
CC		= cc
NAME		= push_swap
LIBFT		= libft.a
RM		= rm -f

SRC		= ./main.c ./swap_operations.c ./rotate_operations.c \
		  ./rev_rotate_operations.c ./push_operations.c ./free_stack.c \
		  ./sort_small.c ./merge_sort.c ./isempty_and_check.c
OBJ		= $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make all -C libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I./includes -L./libft -lft

.c.o:
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
	make clean -C libft
	$(RM) $(OBJ)

fclean:	clean
	make fclean -C libft
	$(RM) $(NAME)

re:	fclean all
