#include "../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	a[] = "Hello";
	const char	b[] = "Hello";
	const char	c[] = "Hell";
	const char	d[] = "He";
	const char	e[] = "World";
	const char	f[] = "On top of the World";

	printf("Si el valor es positivo la primer string es mas grande.\n");
	printf("Si el valor es negativo la primer string es mas pequeña.\n");
	printf("Si el valor es zero, las strings son iguales.\n");
	printf("\n");
	printf("Result_ft: %d\n", ft_strncmp(a, b, 6));
	printf("Result_strncmp: %d\n", strncmp(a, b, 6));
	printf("\n");
	printf("Result_ft: %d\n", ft_strncmp(c, d, 4));
	printf("Result_strncmp: %d\n", strncmp(c, d, 4));
	printf("\n");
	printf("Result_ft: %d\n", ft_strncmp(e, f, 10));
	printf("Result_strncmp: %d\n", strncmp(e, f, 10));
}
