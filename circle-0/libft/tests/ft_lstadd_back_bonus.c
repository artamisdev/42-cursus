#include "../libft.h"
#include <stdio.h>

void print_list(t_list *list) 
{
	t_list *current = list;
	while (current) 
	{
		printf("\"%s\" ➡ ", (char *)current->content);
		current = current->next;
	}
	printf("∅\n");
}

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew((void *)"1");
	a->next = ft_lstnew((void *)"2");
	b = ft_lstnew((void *)"3");

	ft_lstadd_back(&a, b);
	print_list(a);
}
