// io_utils.c
#include "rush02.h"

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putstr(char *s) {
    if (!s) return;
    write(1, s, ft_strlen(s));
}
