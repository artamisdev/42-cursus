#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	t_list	*a;

	a = NULL;
	ft_lstadd_front(&a, ft_lstnew("1"));
	ft_lstadd_front(&a, ft_lstnew("2"));
	ft_lstadd_front(&a, ft_lstnew("3"));
	ft_lstadd_front(&a, ft_lstnew("4"));
	ft_lstadd_front(&a, ft_lstnew("5"));
	ft_lstadd_front(&a, ft_lstnew("6"));
	printf("Result: %d\n", ft_lstsize(a));
}
