#include "../libft.h"
#include <stdio.h>

int main(void)
{
	char *str;

	str = "Olha que coisa mais linda";

	printf("Result: \"%s\"\n", ft_substr(str, 9, 5));
	printf("Result_test: \"%s\"\n", ft_substr("", 1, 1));
	
}
