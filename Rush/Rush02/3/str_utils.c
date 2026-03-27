// str_utils.c
#include "rush02.h"

int ft_strlen(char *s) {
    int i = 0;
    if (!s) return 0;
    while (s[i]) i++;
    return i;
}
