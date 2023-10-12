/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:22:29 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/10 19:01:22 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*to_find;

	i = 0;
	str = (char *)haystack;
	to_find = (char *)needle;
	if (to_find[0] == '\0')
		return (str);
	while (i < len && str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (i + j < len && to_find[j] && str[i + j] == to_find[j])
				j++;
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char	a[] = "Meu amor, voce me da sorte";
	char	b[] = "Meu amor, voce me da sorte";
	char	c[] = "voce";
	char	d[] = "voce";

	printf("Result: %s\n", ft_strnstr(a, c, 20));
	printf("Result: %s\n", strnstr(b, d, 20));
}*/
