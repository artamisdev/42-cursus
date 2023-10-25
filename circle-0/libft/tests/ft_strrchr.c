#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	const char	a[] = "I'm always hungry";
	const char	b[] = "I'm always hungry";

	printf("Result_ft: %s\n", ft_strrchr(a, 'y'));
	printf("Result_strrchr: %s\n", strrchr(b, 'y'));
}
