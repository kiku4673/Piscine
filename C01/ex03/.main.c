#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

void ft_putnbr(int n)
{
	char c;

	if (n <0)
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

int main(void)
{
	int x = 42;
	int y = 4;
	int div = 0;
	int mod = 0;

	write(1, "Before: a = ", 12);
	ft_putnbr(x);
	write(1, ", b = ", 6);
	ft_putnbr(y);
	write(1, "\n", 1);

	ft_div_mod(x, y, &div, &mod);

	write(1, "After: div = ", 13);
	ft_putnbr(div);
	write(1, ", mod = ", 8);
	ft_putnbr(mod);
}