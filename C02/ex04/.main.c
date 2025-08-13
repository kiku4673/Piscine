#include <unistd.h>

int	ft_str_is_lowercase(char *str);

int	main(void)
{
	char *str = "aaaaa";
	char a;

	a = ft_str_is_lowercase(str) + '0';
	write (1, &a, 1);
}
