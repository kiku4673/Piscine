#include <stdio.h>
#include <stdlib.h>

int ft_find_next_prime(int nb);

int main(int argc, char **argv)
{
	int nb;
	int i;

	i = 1;
	while (argc >= 2 && argc > i)
	{
		nb = atoi(argv[i]);
		printf("%d:%d\n", nb, ft_find_next_prime(nb));
		i++;
	}
	return (0);
}

// ./a.out 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40
// ./a.out 31 37 41 43 47 73 79 83 89 97 101 103 107 109 113