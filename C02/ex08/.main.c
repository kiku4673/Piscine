#include <unistd.h>
char	*ft_strlowcase(char	*str);
int	ft_strlen(char *str);

int	main(void)
{
	char str[] = "AAAHSJ";
	int len;

	len = ft_strlen(str);
	write(1, str, len);
	write(1, "\n", 1);
	ft_strlowcase(str);
	write(1, str, len);
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i]!='\0')
		i++;
	return(i);
}