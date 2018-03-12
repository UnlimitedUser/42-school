#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/01/20 20:47:20 by dsclearo          #+#    #+#             *#
#*   Updated: 2017/01/30 22:31:12 by dsclearo         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS = srcs/*.c
CC = gcc
FLAGS = -Wall -Werror -Wextra -Ofast
NAME = wolf3d
LIBS = -Llibft -lft -lm -lmlx -lXext -lX11#-lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(FLAGS) $(SRCS) $(LIBS) -o $(NAME)

clean:
	make -C libft clean
	rm -rf *.o

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all

fast:
	$(CC) $(FLAGS) $(SRCS) $(LIBS) -o $(NAME)

