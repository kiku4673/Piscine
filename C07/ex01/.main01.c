#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max);

int main(void)
{
	int	*arr;
	int	i;
	int min = 3;
	int max = 20;

	arr = ft_range(min, max);
	if (arr == NULL)
		printf ("NULL\n");
	else
	{
		for (i = 0; i < max - min; i++)
			printf("%d ", arr[i]);
		printf("\n");
		free(arr);
	}
	return (0);
}