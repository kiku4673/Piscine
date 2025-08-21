#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	s1[] = "kikuko";
	char	s2[] = "kikuno";

	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%d\n", ft_strcmp(s1, s2));
	printf("%d\n", strcmp(s1, s2));
}
