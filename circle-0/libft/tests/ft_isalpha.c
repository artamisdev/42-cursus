#include "../libft.h"
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	x;
	int	z;

	x = 'F';
	z = '4';
	printf("Result_ft: %d\n", ft_isalpha(x));
	printf("Result_isalpha: %d\n", isalpha(x));
	printf("\n");
	printf("Result_ft: %d\n", ft_isalpha(z));
	printf("Result_isalpha: %d\n", isalpha(z));
}
