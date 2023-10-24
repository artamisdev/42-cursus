#include "../libft.h"
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int x;

	x = 222;

	printf("Result_ft: %d\n", ft_isascii(x));
	printf("Result_isascii: %d\n", isascii(x));
}
