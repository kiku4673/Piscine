
#include <unistd.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

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
	char dest2[50] = "shirituebisuchugaku1";
	char dest3[50] = "kiku2";
	char dest4[50] = "shirituebisuchugaku2";
	char src[50] = "Hello, world";

	write(1, "==test_ft_strncopy==\n", sizeof("==test_ft_strncopy==\n")-1);

	write(1, "src : ", 6);
	len = ft_strlen(src);
	write(1, src, len);
	write(1, "\ndest1 : ", 9);
	len = ft_strlen(dest1);
	write(1, dest1, len);
	write(1, "\n", 1);

	ft_strncpy(dest1, src, 20);

	write(1, "src : ", 6);
	len = ft_strlen(src);
	write(1, src, len);
	write(1, "\ndest1 : ", 9);
	len = ft_strlen(dest1);
	write(1, dest1, len);
	write(1, "\n", 1);

//------------------------------

	write(1, "src : ", 6);
	len = ft_strlen(src);
	write(1, src, len);
	write(1, "\ndest2 : ", 9);
	len = ft_strlen(dest2);
	write(1, dest2, len);
	write(1, "\n", 1);

	ft_strncpy(dest2, src, 20);

	write(1, "src : ", 6);
	len = ft_strlen(src);
	write(1, src, len);
	write(1, "\ndest2 : ", 9);
	len = ft_strlen(dest2);
	write(1, dest2, len);
	write(1, "\n", 1);

	write(1, "\n==test_strncopy==\n", sizeof("\n==test_strncopy==\n")-1);

	write(1, "src : ", 6);
	len = ft_strlen(src);
	write(1, src, len);
	write(1, "\ndest2 : ", 9);
	len = ft_strlen(dest2);
	write(1, dest2, len);
	write(1, "\n", 1);

	strncpy(dest2, src, 5);

	write(1, "src : ", 6);
	len = ft_strlen(src);
	write(1, src, len);
	write(1, "\ndest2 : ", 9);
	len = ft_strlen(dest2);
	write(1, dest2, len);
	write(1, "\n", 1);
	return (0);
}
