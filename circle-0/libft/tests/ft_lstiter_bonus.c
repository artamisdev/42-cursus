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

void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

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

	print_list(a);
	ft_lstiter(a, print_content);
}
