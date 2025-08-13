#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int arr[] = { 50, 20, 10, 40, 60};
	int	n = sizeof(arr) / sizeof(arr[0]);

	printf("Before :\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	ft_sort_int_tab(arr, n);

	printf("After :\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}