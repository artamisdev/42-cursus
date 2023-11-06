#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	int	num;
	char	*result;

	num = -123456;

	result = ft_itoa(num);

	printf("Result_ft_itoa: %s\n", result);
}
