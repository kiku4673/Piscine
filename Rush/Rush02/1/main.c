// main.c
#include "rush02.h"
#include <stdlib.h> // free

int main(void)
{
    char *content = read_all_file("numbers.dict");
    if (!content)
    {
        ft_putstr("Error: cannot read file\n");
        return (1);
    }
    ft_putstr(content);
    free(content);
    return (0);
}
