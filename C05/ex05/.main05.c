#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb);

int main(int argc, char **argv)
{
	int	nb;

	if (argc == 2)
	{
		nb = atoi(argv[1]);
		printf("%d\n", ft_sqrt(nb));
	}
	return (0);
}

// ./a.out 16
// ./a.out 99980001
// ./a.out 2147395600 