# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 12:08:40 by deelliot          #+#    #+#              #
#    Updated: 2022/01/26 13:32:50 by deelliot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c

INCLS = ./get_next_line.h

OBJS = get_next_line.o

BIN_DIR = .

EXE := $(BIN_DIR)/$(NAME)

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -I libft/includes -c $(SRCS) -o $(OBJS) $(CFLAGS)
	gcc -I libft/includes -o main.o -c main.c $(CFLAGS)
	gcc -o $(NAME) main.o get_next_line.o -I libft/includes -L libft/ -lft


clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

.PHONY: all fclean clean re lib

$(V).SILENT:

