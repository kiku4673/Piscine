#include <unistd.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	char *str = "098765432wdfg";
	char a;

	a = ft_str_is_printable(str) + '0';
	write (1, &a, 1);
}
