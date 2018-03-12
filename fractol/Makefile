#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/01/14 23:46:34 by dsclearo          #+#    #+#             *#
#*   Updated: 2017/01/18 13:46:35 by dsclearo         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS = srcs/*.c
LIBS = -Llibft -lft -lmlx -framework OpenGL -framework AppKit -lm
NAME = fractol
CC = gcc
FLAGS = -Wall -Werror -Wextra -Ofast

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(FLAGS) $(SRCS) $(LIBS) -o $(NAME)

clean:
	make -C libft clean

fclean:
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all

fast:
	$(CC) $(FLAGS) $(SRCS) $(LIBS) -o $(NAME)
