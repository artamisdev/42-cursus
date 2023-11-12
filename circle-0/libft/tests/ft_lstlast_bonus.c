#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	t_list	*a;

	a = NULL;
	ft_lstadd_front(&a, ft_lstnew("a"));
	ft_lstadd_front(&a, ft_lstnew("b"));
	ft_lstadd_front(&a, ft_lstnew("c"));
	ft_lstadd_front(&a, ft_lstnew("d"));
	ft_lstadd_front(&a, ft_lstnew("e"));
	ft_lstadd_front(&a, ft_lstnew("f"));
	ft_lstadd_front(&a, ft_lstnew("g"));
	printf("Result_last_node: %s\n", ft_lstlast(a)->content);
}
