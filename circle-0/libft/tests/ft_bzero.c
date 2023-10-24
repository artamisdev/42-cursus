#include "../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	i[] = "Galera de cowboy";
	char	j[] = "Galera de cowboy";

	ft_bzero(i+3, 5);
	printf("Result: %s\n", i);

	bzero(j+3, 5);
	printf("Result: %s\n", j);
}
