# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 18:33:21 by bolcay            #+#    #+#              #
#    Updated: 2025/02/06 15:08:33 by bolcay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = error_handling.c pusher.c reverse_rotater.c rotater.c swapper.c \
		create_stack.c helper_functions.c algorithm.c split.c main.c \
		organise_the_numbers.c deallocation.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -fr
NAME = push_swap

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re