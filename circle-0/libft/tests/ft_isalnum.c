#include "../libft.h"
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int i;
	int j;
	int	x;
	int z;

	i = '%';
	j = '6';
	x = 'e';
	z = 'A';

	printf("Result: %d\n", isalnum(i));
	printf("Result_ft: %d\n", ft_isalnum(i));
	printf("\n");
	printf("Result: %d\n", isalnum(j));
	printf("Result_ft: %d\n", ft_isalnum(j));
	printf("\n");
	printf("Result: %d\n", isalnum(x));
	printf("Result_ft: %d\n", ft_isalnum(x));
	printf("\n");
	printf("Result: %d\n", isalnum(z));
	printf("Result_ft: %d\n", ft_isalnum(z));

}
