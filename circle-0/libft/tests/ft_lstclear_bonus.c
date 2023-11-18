#include "../libft.h"
#include <stdio.h>

void	print_list(t_list *list)
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
	char	*content1;
	char	*content2;
	char	*content3;
	char	*content4;

	content1 = ft_calloc(1, sizeof(char));
	content2 = ft_calloc(1, sizeof(char));
	content3 = ft_calloc(1, sizeof(char));
	content4 = ft_calloc(1, sizeof(char));
	content1[0] = '1';
	content2[0] = '2';
	content3[0] = '3';
	content4[0] = '4';
	a = ft_lstnew(content1);
	ft_lstadd_back(&a, ft_lstnew(content2));
	ft_lstadd_back(&a, ft_lstnew(content3));
	ft_lstadd_back(&a, ft_lstnew(content4));

	print_list(a);
	ft_lstclear(&a, free);
	print_list(a);
}
