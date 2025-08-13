#include <unistd.h>

int	 ft_strlen(char *str);

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(void)
{

	char *test_str = "Hello, world!";
	int	length = ft_strlen(test_str);

	write(1, "length: ", 8);
	ft_putnbr(length);
	write(1, "\n", 1);
}
