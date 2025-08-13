
#include <unistd.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src);

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int main(void)
{
	int len;
	char dest1[50] = "kiku1";
	char dest2[50] = "kiku2";
	char src[50] = "Hello";

	len = ft_strlen(dest1);
	write(1, dest1, len);
	write(1, "\n", 1);

	ft_strcpy(dest1, src);

	len = ft_strlen(dest1);
	write(1, dest1, len);
	write(1, "\n", 1);

	len = ft_strlen(dest2);
	write(1, dest2, len);
	write(1, "\n", 1);

	strcpy(dest2, src);

	len = ft_strlen(dest2);
	write(1, dest2, len);
	write(1, "\n", 1);

	return (0);
}