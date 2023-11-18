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

char	*ft_strupcase(char *str)
{
	int	offset;
	int	i;

	offset = 'a' - 'A';
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= offset;
		i++;
	}
	return (str);
}

void	*f(void *content)
{
	return ft_strupcase(content);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;

	char content1[] = "a";
	char content2[] = "b";
	char content3[] = "c";
	char content4[] = "d";
	char content5[] = "e";

	a = ft_lstnew(content1);
	ft_lstadd_front(&a, ft_lstnew(content2));
	ft_lstadd_front(&a, ft_lstnew(content3));
	ft_lstadd_front(&a, ft_lstnew(content4));
	ft_lstadd_front(&a, ft_lstnew(content5));

	print_list(a);
	b = ft_lstmap(a, f, free);
	print_list(b);
}
