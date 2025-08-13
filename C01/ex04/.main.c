#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b);

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
	int	a = 42;
	int	b = 0;

	write(1, "Before: a = ", 12);
	ft_putnbr(a);
	write(1, ", b = ", 6);
	ft_putnbr(b);
	write(1, "\n", 1);

	ft_ultimate_div_mod(&a, &b);

	write(1,"After: a = ", 11);
	ft_putnbr(a);
	write(1, ", b = ", 6);
	ft_putnbr(b);
	write(1, "\n", 1);
}