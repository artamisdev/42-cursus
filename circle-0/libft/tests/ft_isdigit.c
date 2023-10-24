#include "../libft.h"
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	a;
	int	b;

	a = '5';
	b = '$';
	printf("Result ft_isdigit: %d\n", ft_isdigit(a));
	printf("Result isdigit: %d\n", isdigit(a));
	printf("\n");
	printf("Result ft_isdigit: %d\n", ft_isdigit(b));
	printf("Result isdigit: %d\n", isdigit(b));
}
