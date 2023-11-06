#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	char	*str;
	char	c;
	char	**result;

	str = "I see the crystal raindrops fall And the beauty of it all Is when the sun comes shining through To make those rainbows in my mind When I think of you sometime And I wanna spend some time with you";
	c = ' ';
	result = ft_split(str, c);
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
}
