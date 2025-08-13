#include <unistd.h>

void	ft_ultimate_ft(int *********nbr);

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
	int		nbr = 0;
	int		*ptr1 = &nbr;
	int		**ptr2 = &ptr1;
	int		***ptr3 = &ptr2;
	int		****ptr4 = &ptr3;
	int		*****ptr5 = &ptr4;
	int		******ptr6 = &ptr5;
	int		*******ptr7 = &ptr6;
	int		********ptr8 = &ptr7;
	int		*********ptr9 = &ptr8;

	write(1, "Before: ", 8);
	put_number(nbr);
	write(1, "\n", 1);

	ft_ultimate_ft(ptr9);

	write(1, "After: ", 7);
	put_number(nbr);
	write(1, "\n", 1);

	return 0;
}
