// file_utils.c
#include "rush02.h"
#include <fcntl.h>   // open
#include <unistd.h>  // read, close
#include <stdlib.h>  // malloc

#define BUF_SIZE 1024

char *read_all_file(char *filename)
{
    int  fd;
    int  size;
    int  total;
    char buf[BUF_SIZE];
    char *result;
    char *tmp;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);

    result = NULL;
    total = 0;
    while ((size = read(fd, buf, BUF_SIZE)) > 0)
    {
        tmp = malloc(total + size + 1);
        if (!tmp)
            return (NULL);
        for (int i = 0; i < total; i++)
            tmp[i] = result ? result[i] : 0;
        for (int j = 0; j < size; j++)
            tmp[total + j] = buf[j];
        tmp[total + size] = '\0';
        free(result);
        result = tmp;
        total += size;
    }
    close(fd);
    return (result);
}
