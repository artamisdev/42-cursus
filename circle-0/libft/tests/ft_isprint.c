#include "../libft.h"
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	x;

	x = 32;

	printf("Result_ft: %d\n", ft_isprint(x));
	printf("Result: %d\n", isprint(x));

}
