#include "../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "This is the copy";
	char	*copy1;
	char	*copy2;
   
	copy1 = strdup(src);
	copy2 = ft_strdup(src);

	src[3] = 'a';
	printf("Result_src: %s\n", src);
	printf("Result_strdup: %s\n", copy1);
	printf("Result_ft: %s\n", copy2);
}
