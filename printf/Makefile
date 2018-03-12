#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/12/13 18:26:52 by dsclearo          #+#    #+#             *#
#*   Updated: 2016/12/13 18:32:08 by dsclearo         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS = *.c
OBJS = *.o
CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) -c $(SRCS) $(FLAGS)
	ar rc $(NAME) $(OBJS) libft/$(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all
