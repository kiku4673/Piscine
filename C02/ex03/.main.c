#include <unistd.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	char *str = "00000e000";
	char a;

	a = (ft_str_is_numeric(str)) + '0';
	write (1, &a, 1);
}
