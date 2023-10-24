#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	i[] = "0123456789";
	char	*j;
	char	x[] = "0123456789";
	char	*z;
	char	*result1;
	char	*result2;

	j = i + 5;
	z = x + 5;

	result1 = ft_memmove(i, j, 8);
	result2 = memmove(x, z, 8);

	printf("Result_ft: %s\n", result1);
	printf("Result: %s\n", result2);

}
