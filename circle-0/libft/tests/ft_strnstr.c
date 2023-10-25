#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	a[] = "Meu amor, voce me da sorte";
	char	b[] = "Meu amor, voce me da sorte";
	char	c[] = "voce";
	char	d[] = "voce";

	printf("Result_ft: %s\n", ft_strnstr(a, c, 20));
	printf("Result_strnstr: %s\n", strnstr(b, d, 20));
}
