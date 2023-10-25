#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	i[] = "you got this!";
	char	*result1;
	char	*result2;

	result1 = ft_memset(i, 'H', 6);
	result2 = memset(i, 'H', 6);
	

	printf("Result_ft: %s\n", result1);
	printf("Result_memset: %s\n", result2);
}
