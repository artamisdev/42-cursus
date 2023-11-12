#include "../libft.h"
#include <stdio.h>

int main(void)
{	
	t_list	*result;
	
	result = ft_lstnew((void *)23);
	printf("Content: %d\n", (int)result->content);
}
