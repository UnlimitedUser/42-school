#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/01/08 12:38:57 by dsclearo          #+#    #+#             *#
#*   Updated: 2017/01/13 22:27:00 by dsclearo         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS = srcs/*.c
CC = gcc
FLAGS = -Wall -Werror -Wextra -Ofast
NAME = lem-in
LIB = -Llibft -lft

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(FLAGS) $(SRCS) $(LIB) -o $(NAME)

clean:
	@make -C libft clean

fclean:
	@make -C libft fclean
	@rm -rf $(NAME)

re: fclean all

fast:
	@$(CC) $(FLAGS) $(SRCS) $(LIB) -o $(NAME)
