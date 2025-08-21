#include <stdio.h>

unsigned int ft_strlen(char *s);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int main(void)
{
    char buf1[20] = "Hello, ";
    char *src1 = "World!";
    unsigned int size1 = sizeof(buf1);

    char buf2[10] = "Hi";
    char *src2 = "There";
    unsigned int size2 = sizeof(buf2);

    char buf3[10] = "Hi";
    char *src3 = NULL; // src が NULL の場合
    unsigned int size3 = sizeof(buf3);

    char buf4[5] = "Hello";
    char *src4 = "World"; // size < strlen(dest)
    unsigned int size4 = 5;

    printf("=== Test 1 ===\n");
    printf("Return: %u, Result: %s\n", ft_strlcat(buf1, src1, size1), buf1);

    printf("=== Test 2 ===\n");
    printf("Return: %u, Result: %s\n", ft_strlcat(buf2, src2, size2), buf2);

    printf("=== Test 3 ===\n");
    printf("Return: %u, Result: %s\n", ft_strlcat(buf3, src3, size3), buf3);

    printf("=== Test 4 ===\n");
    printf("Return: %u, Result: %s\n", ft_strlcat(buf4, src4, size4), buf4);

    return 0;
}
