#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char dest1[50] = "Hello ";
	char src[50] = "world!";
	char dest2[50];

	strcpy(dest2, dest1);
	printf("%s\n", dest1);
	printf("%s\n", src);
	printf("%s\n", ft_strcat(dest1, src));
	printf("%s\n", strcat(dest2, src));
}
