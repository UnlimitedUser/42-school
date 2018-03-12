#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/02 22:38:26 by dsclearo          #+#    #+#             *#
#*   Updated: 2016/11/14 21:28:08 by dsclearo         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = fillit
GCC_FLAGS = -Wall -Werror -Wextra
CC = gcc $(GCC_FLAGS)
RM = rm -rf
SRCS = *.c
OBJS = *.o

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

$(OBJS):
	@$(CC) $(SRCS) -c

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
