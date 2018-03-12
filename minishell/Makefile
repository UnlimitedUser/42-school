# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apavalac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 11:00:39 by apavalac          #+#    #+#              #
#    Updated: 2017/05/09 13:35:23 by dansclear        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
DEBUG =
LD = $(CC)
SRCDIR = ./srcs
OBJDIR = ./objs
INCDIR = -I./includes  -I/usr/X11/include/
CC = gcc
CFLAGS= -Wall -Wextra -Werror -O3

LDFLAGS = $(CFLAGS)
SRC = main.c \
	ft_sh1.c \
	use_fork.c \
	ft_builtins.c \
	ft_env.c utils.c utils1.c utils2.c utils3.c

OBJS = $(SRC:.c=.o)
OBJS_PREF = $(addprefix $(OBJDIR)/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS_PREF)
	@$(LD) -o $@ $^ $(LDFLAGS) $(INCDIR) $(LIB_CALL)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCDIR)

clean:
	@rm -f $(OBJS_PREF)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
