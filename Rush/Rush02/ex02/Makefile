NAME    = rush-02
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS = main.c \
       io_utils.c \
       char_utils.c str_len_cmp.c str_mem.c str_trim.c \
       parse_args.c \
       file_read.c dict_kv.c dict_parse.c dict_load.c dict_free.c dict_query.c \
       convert_small.c convert_big.c convert_split.c convert_tail.c \
       num_utils.c print_word.c

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
