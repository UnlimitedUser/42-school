#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/28 00:00:27 by dsclearo          #+#    #+#             *#
#*   Updated: 2016/11/28 20:58:26 by dsclearo         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CC = gcc
NAME = fdf
SRC = *.c
LIB = -lmlx -framework OpenGL -framework AppKit
LIBFT = libft
MYLIB = -Llibft -lft
FLAGS = -Wall -Werror -Wextra -Ofast

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(SRC) -c $(FLAGS)
	$(CC) *.o $(FLAGS) $(LIB) $(MYLIB) -o $(NAME)

clean:
	rm -rf *.o
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
