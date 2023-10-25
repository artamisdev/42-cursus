#include "../libft.h"
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	i;
	int	j;

	i = 'a';
	j = 'a';
	printf("Result_ft: %c\n", ft_toupper(i));
	printf("Result_toupper: %c\n", toupper(j));
}
