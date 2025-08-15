#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int main(void)
{
	unsigned int a;
	char dest1[10] = "kiku1";
	// char dest2[10] = "kiku2";
	char src[] = "Hello, world!";

	printf("%s\n", dest1);
	a = ft_strlcpy(dest1,src,sizeof(dest1));
	printf("%s\n", dest1);
	printf("%d\n", a);

	// printf("%s\n", dest2);
	// a = strlcpy(dest2,src,sizeof(dest2));
	// printf("%s\n", dest2);
	// printf("%d\n", a);

}