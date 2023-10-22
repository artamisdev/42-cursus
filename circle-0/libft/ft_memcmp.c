/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:55:57 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/15 18:56:10 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;
	const char		*str1;
	const char		*str2;

	if (n == 0)
		return (0);
	i = 0;
	str1 = s1;
	str2 = s2;
	c1 = str1[0];
	c2 = str2[0];
	while (i < n && c1 == c2)
	{
		c1 = str1[i];
		c2 = str2[i];
		i++;
	}
	return (c1 - c2);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	a[] = "That's all folks";
	const char	b[] = "That's all folks";
	const char	c[] = "That's it girl";
	const char	d[] = "That's it girl";

	printf("Result: %d\n", ft_memcmp(a, c, 16));
	printf("Result: %d\n", memcmp(b, d, 16));
}*/
