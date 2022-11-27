# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 14:10:59 by ddemers           #+#    #+#              #
#    Updated: 2022/11/27 14:10:59 by ddemers          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra
REMOVE = rm -f
OBJS = ${SRC:.c=.o}
SRC = ./src/pipex.c
$(NAME): ${OBJS}
		 ${LIBC} $(NAME) ${OBJS}
all:$(NAME)

clean :
		${REMOVE} ${OBJS}

fclean :clean
		${REMOVE} $(NAME)

re:fclean all

.PHONY: all clean fclean re 
