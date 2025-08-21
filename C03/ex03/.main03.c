#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char dest1[50] = "Hello ";
	char src[50] = "world!";
	unsigned int nb = 6;
	char dest2[50];

	strcpy(dest2, dest1);
	printf("%s\n", dest1);
	printf("%s\n", src);
	printf("%s\n", ft_strncat(dest1, src, nb));
	printf("%s\n", strncat(dest2, src, nb));
}
