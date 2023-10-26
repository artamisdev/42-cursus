#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	char	*to_set;
	char	*str;
	char	*result;

	str = ".,.,.,azul del mar..,,.,";
	to_set = ".,";

	result = ft_strtrim(str, to_set);

	printf("Result_ft_strtrim: %s\n", result);
}
