# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/05 14:06:19 by dsclearo          #+#    #+#              #
#*   Updated: 2017/02/24 17:02:01 by dsclearo         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

OBJ = *.o
SRC = *.c
NAME = libft.a
FLAGS = -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ):
	@gcc $(FLAGS) $(SRC)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
