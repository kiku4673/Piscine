#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int main(void)
{
	int	*arr;
	int	size;
	int	i;

	/*正常ケース*/
	size = ft_ultimate_range(&arr, 3, 10);
	printf("size = %d\n", size);
	if(arr != NULL)
	{
		for (i = 0; i < size; i++)
			printf("%d ", arr[i]);
		printf("\n");
		free(arr);
	}

	/* min == max のケース　*/
	size = ft_ultimate_range(&arr, 5, 5);
	printf("size = %d (arr = %p)\n", size, (void *)arr);

	/* min > max のケース */
	size = ft_ultimate_range(&arr, 10, 3);
	printf("size = %d (arr = %p)\n", size, (void *)arr);

	return (0);
}
