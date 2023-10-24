#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*str = ft_calloc(6, sizeof(char));
	char	*str2 = calloc(6, sizeof(char));
	int	result;

	result = ft_memcmp(str, str2, 6);
	
	if (result == 0)
		printf("Success");
	else
			printf("Fail");
}
