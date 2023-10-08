/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:03:27 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/08 17:22:34 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	if (n == 0)
		return (0);
	i = 0;
	c1 = s1[0];
	c2 = s2[0];
	while (i < n && c1 && c2 && c1 == c2)
	{
		c1 = s1[i];
		c2 = s2[i];
		i++;
	}
	return (c1 - c2);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	a[] = "Hello";
	const char	b[] = "Hello";
	const char	c[] = "Hell";
	const char	d[] = "He";
	const char	e[] = "World";
	const char	f[] = "On top of the World";

	printf("Si el valor es positivo la primer string es mas grande.\n");
	printf("Si el valor es negativo la primer string es mas pequeña.\n");
	printf("Si el valor es zero, las strings son iguales.\n");
	printf("\n");
	printf("Result: %d\n", ft_strncmp(a, b, 6));
	printf("Result: %d\n", strncmp(a, b, 6));
	printf("\n");
		printf("Result: %d\n", ft_strncmp(c, d, 4));
	printf("Result: %d\n", strncmp(c, d, 4));
	printf("\n");
	printf("Result: %d\n", ft_strncmp(e, f, 10));
	printf("Result: %d\n", strncmp(e, f, 10));
}*/
