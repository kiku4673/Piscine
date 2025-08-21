#include <stdio.h>
#include <stdlib.h>

int	ft_fibonacci(int index);

int	main(int argc, char **argv)
{
	int index;

	if (argc == 2)
	{
		index = atoi(argv[1]);
		printf("%d\n", ft_fibonacci(index));
	}
	return (0);
}
