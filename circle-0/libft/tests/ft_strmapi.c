#include "../libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char to_uppercase(unsigned int i, char c) {
	if (i) {}
	return toupper(c);
}

int	main(void)
{
	char	*s;
	char	*result;

	s = "gato";
	printf("Original: %s\n", s);
	result = ft_strmapi(s, to_uppercase);
	printf("Result_ft_strmapi: %s\n", result);
}
