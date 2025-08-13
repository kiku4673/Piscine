#include <unistd.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	char *str = "AAAAAA";
	char a;

	a = ft_str_is_uppercase(str) + '0';
	write (1, &a, 1);
}
