#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	const char	a[] = "All we need is hope";
	const char	b[] = "All we need is hope";
	char	*result1;
	char	*result2;

	result1 = ft_strchr(a, 'h');
	result2 = strchr(b, 'h');

	printf("Result_ft: %s\n", result1);
	printf("Result_strchr: %s\n", result2);
}
