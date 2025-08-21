#include <stdio.h>
#include <stdlib.h>

int	ft_recursive_power(int nb, int power);

int	main(int argc, char **argv)
{
	int nb;
	int	power;

	if (argc == 3)
	{
		nb = atoi(argv[1]);
		power = atoi(argv[2]);
		printf("nb: %d\npower: %d\n = %d\n", nb, power, ft_recursive_power(nb,power));
	}
	return (0);
}
