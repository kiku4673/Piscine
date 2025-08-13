#include <unistd.h>

void ft_ft(int *nbr);


void	put_number(int n)
{
	char	c;

	if (n >= 10)
	{
		put_number(n / 10);
	}

	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(void)
{
	int	number;

	number = 0;

	write(1, "Before: ", 8);
	put_number(number);
	write(1, "\n", 1);

	ft_ft(&number);

	write(1, "After: ", 7);
	put_number(number);
	write(1, "\n", 1);

	return (0);
}
