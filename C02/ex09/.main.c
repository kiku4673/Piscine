#include <stdio.h>

char	*ft_strcapitalize(char *str);

int main(void)
{
	char s[] = "hi, How are you? 42words forty-tow; fifty+and+one";
	printf("%s\n", ft_strcapitalize(s));
	return 0;
}
