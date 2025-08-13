#include <unistd.h>

int	ft_str_is_alpha(char *str);

int	main(void)
{
	char *str = "Hello";
	char a;

	a = (ft_str_is_alpha(str)) + '0';
	write (1, &a, 1);
}
