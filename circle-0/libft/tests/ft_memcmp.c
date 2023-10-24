#include "../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	a[] = "That's all folks";
	const char	b[] = "That's all folks";
	const char	c[] = "That's it girl";
	const char	d[] = "That's it girl";

	printf("Result_ft: %d\n", ft_memcmp(a, c, 16));
	printf("Result: %d\n", memcmp(b, d, 16));
}
