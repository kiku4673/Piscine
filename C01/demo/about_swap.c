#include <stdio.h>

void swap(int* a, int* b);

int main(void)
{
    int a = 10, b = 100;
    printf("a = %3d : b = %3d\n", a, b);
    swap(&a, &b);
    printf("a = %3d : b = %3d\n", a, b);
    return 0;
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}