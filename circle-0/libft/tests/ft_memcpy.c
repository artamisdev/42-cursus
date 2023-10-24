#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	i[] = "12345";
	char	j[] = "abcdef";
	char	x[] = "socorro3us";
	char	z[] = "nolosemanada!";
	char	*result1;
	char	*result2;
	char	*result3;
	char	*result4;


	result1 = ft_memcpy(j, i, 5);
	result2 = memcpy(j, i, 5);
	result3 = ft_memcpy(z, x, 8);
	result4 = memcpy(z, x, 8);


	printf("Result_ft: %s\n", result1);
	printf("Result: %s\n", result2);
	printf("\n");
	printf("Result_ft: %s\n", result3);
	printf("Result: %s\n", result4);
}
