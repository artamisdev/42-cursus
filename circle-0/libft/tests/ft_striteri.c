#include "../libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

 void    to_uppercase(char *c) 
{
	*c = toupper(*c);
}

int	main(void)
{
	char	*s;
	
	s = "i'm always hungry";
	printf("Original: %s\n", s);
	ft_striteri(s, to_uppercase);
	printf("Result_ft_striteri: %s\n", s);
}
