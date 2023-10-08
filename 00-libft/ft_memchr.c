/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:26:18 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/08 18:46:28 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	chr;

	i = 0;
	str = (char *)s;
	chr = c;
	while (i < n)
	{
		if (str[i] == chr)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	const char	a[] = "That's all folks";
	const char	b[] = "That's all folks";

	printf("Result: %s\n", ft_memchr(a, 'f', 17));
	printf("Result: %s\n", memchr(b, 'f', 17));
}*/
