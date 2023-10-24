#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	*a;
	char	*b;
	char	*result;
	char	*result2;

	a = "That's all folks";
	b = "That's all folks";

	result = ft_memchr(a, 'f', 17);
	result2 = memchr(b, 'f', 17);
	
	printf("Result_ft: %s\n", result);
	printf("Result: %s\n", result2);
}
