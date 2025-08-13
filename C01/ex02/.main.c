#include <unistd.h>

void	ft_swap(int *a, int *b);

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
	int x = -66;
	int y = 99;

	write(1, "Before swap: x = ", sizeof("Before swap: x = ") - 1);
	ft_putnbr(x);
	write(1, ", y = ", sizeof(", y = ") - 1);
	ft_putnbr(y);
	write(1, "\n", 1);

	ft_swap(&x, &y);

	write(1, "After swap: x = ", sizeof("After swap: x = ") - 1);
	ft_putnbr(x);
	write(1, ", y = ", sizeof(", y = ") - 1);
	ft_putnbr(y);
	write(1, "\n", 1);
}
