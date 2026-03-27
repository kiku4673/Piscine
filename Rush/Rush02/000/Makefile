NAME = rush-02

SRCS = rush-02.c \
       string_utils.c \
       number_utils.c \
       dict_utils.c \
       dict_parser.c \
       number_converter.c \
       number_math.c \
       number_processing.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re