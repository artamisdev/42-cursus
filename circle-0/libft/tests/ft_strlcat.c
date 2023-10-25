#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char		dst_a[20] = "Primeira";
	const char	src_a[] = "&Segunda";
	char		dst_b[20] = "Primeira";
	const char	src_b[] = "&Segunda";
	
	printf("Result_ft: %zu\n", ft_strlcat(dst_a, src_a, 17));
	printf("Result_strlcat: %zu\n", strlcat(dst_b, src_b, 17));
}
