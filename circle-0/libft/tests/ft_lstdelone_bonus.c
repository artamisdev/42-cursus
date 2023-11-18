#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	char	*name;
	t_list	*node;

	name = ft_calloc(5, sizeof(char));
	name[0] = 't';
	name[1] = 'i';
	name[2] = 't';
	name[3] = 'o';
	
	node = ft_lstnew(name);
	printf("Result_del_one: %s\n", node->content);
	ft_lstdelone(node, free);
	printf("Result_del_one: %s\n", node->content);
}
