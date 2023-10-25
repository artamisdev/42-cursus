#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	char	*a;
	char	*b;
	char	*result;

	a = "One ";
	b = "and Two";
	result = ft_strjoin(a, b);

	printf("Result_ft_strjoin: %s\n", result);
}
