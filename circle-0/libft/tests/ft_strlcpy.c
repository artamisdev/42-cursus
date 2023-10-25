#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	i[] = "Primeira";
	char	j[] = "Segunda";
	char	x[] = "Primeira";
	char	z[] = "Segunda";

	printf("Result_ft: %lu\n", ft_strlcpy(i, j, 4));
	printf("Result_strlcpy: %zu\n", strlcpy(x, z, 4));
	printf("%s\n", i);
	printf("%s\n", j);
	printf("%s\n", x);
	printf("%s\n", z);
}
