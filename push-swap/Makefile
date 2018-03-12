#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/01/02 21:38:16 by dsclearo          #+#    #+#             *#
#*   Updated: 2017/01/09 17:29:28 by dsclearo         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CC = gcc
FLAGS = -Wall -Werror -Wextra -Ofast
CHECKER = checker
PUSH_SWAP = push_swap
COMMON = srcs/utils* srcs/show_stacks.c srcs/exit_on_error.c srcs/is_sort.c \
	srcs/put_in_stack.c srcs/exec_func.c srcs/verbose.c
LIB = -Llibft -lft
LIBFT = libft.a
NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(PUSH_SWAP) $(CHECKER)

$(LIBFT):
	make -C libft

$(PUSH_SWAP):
	$(CC) $(FLAGS) $(COMMON) srcs/push_swap.c -o $(PUSH_SWAP) $(LIB)

$(CHECKER):
	$(CC) $(FLAGS) $(COMMON) srcs/checker.c -o $(CHECKER) $(LIB)

clean:
	make -C libft clean
	rm -rf *.o

fclean: clean
	make -C libft fclean
	rm -rf $(CHECKER)
	rm -rf $(PUSH_SWAP)

re: fclean all
