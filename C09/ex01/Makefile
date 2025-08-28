NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

#src files must be explicitly named
SRCS = srcs/ft_putchar.c \
	   srcs/ft_putstr.c \
	   srcs/ft_strcmp.c \
	   srcs/ft_strlen.c \
	   srcs/ft_swap.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

# make libft.a
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# compile, timestamp cmp
srcs/%.o: srcs/%.c includes/ft.h
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	rm -f $(OBJS)

# full clean
fclean: clean
	rm -f $(NAME)

# rebuild
re: fclean all

.PHONY: all clean fclean re