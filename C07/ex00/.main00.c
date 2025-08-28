#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char *src = "kikuno";
	char *dup1, *dup2;

	dup1 = ft_strdup(src);
	dup2 = strdup(src);

	printf ("%s\n", dup1);
	printf ("%s\n", dup2);

	free(dup1);
	free(dup2);

	return (0);
}
