#include "../libft.h"
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	i;
	int	j;

	i = 'A';
	j = 'A';
	printf("Result_ft: %c\n", ft_tolower(i));
	printf("Result_tolower: %c\n", tolower(j));
}
