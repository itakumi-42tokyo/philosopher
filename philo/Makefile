# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 13:06:06 by itakumi           #+#    #+#              #
#    Updated: 2025/09/07 14:13:26 by itakumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

override NAME			= philo

CC						?= cc

override CFLAGS			= -Wall -Wextra -Werror

override PTHREAD_FLAG	= -lpthread

SRC						=	main.c \
						

VPATH					= src:include:src/

OBJ_DIR					?= build/

LIB_DIR					?= lib/

OBJS					= $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

$(NAME): $(OBJS)

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $()

clean:

fclean:

re:

debug: CFLAGS=
debug: all

.PHONY: all clean fclean re debug
