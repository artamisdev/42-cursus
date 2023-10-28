#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	char	*char_set;
	char	*str;
	char	*result;

	str = ".,.,.,azul del mar..,,.,";
	char_set = ".,";

	result = ft_strtrim(str, char_set);

	printf("Result_ft_strtrim: %s\n", result);
}
