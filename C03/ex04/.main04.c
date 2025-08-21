#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int main(void)
{
	char str1[50] = "Hello";
	char to_find[50] = "leo";
	char str2[50];

	strcpy(str2, str1);
	printf("%s\n", ft_strstr(str2, to_find));
	printf("%s\n", strstr(str2, to_find));
}