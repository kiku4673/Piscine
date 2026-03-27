# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 11:39:10 by kyamanak          #+#    #+#              #
#    Updated: 2025/08/24 19:57:36 by kyamanak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = rush-02
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = main.c parse_args.c str_utils.c io_utils.c\
		dict_parse_utils.c dict_parse.c dict_load.c dict_query.c\
		dict_read.c convert.c c_convert_block.c c_convert_scale.c\
		c_say.c c_scales.c c_untils.c str.c Error.c\

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