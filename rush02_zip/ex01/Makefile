# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 11:39:10 by kyamanak          #+#    #+#              #
#    Updated: 2025/08/23 14:13:06 by kyamanak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = rush-02
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = main.c parse_args.c dict_load.c dict_query.c convert.c \
          str_utils.c io_utils.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c rush02.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re