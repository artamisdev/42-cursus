/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:59:28 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/15 18:57:25 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	if (!dst && !src)
		return (0);
	dest = (char *)dst;
	source = (char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char	i[] = "12345";
	char	j[] = "abcdef";
	char	x[] = "socorro3us";
	char	z[] = "nolosemanada!";

	printf("Result: %s\n", ft_memcpy(j, i, 5));
	printf("Result: %s\n", ft_memcpy(z, x, 8));
	printf("Result: %s\n", memcpy(j, i, 5));
	printf("Result: %s\n", memcpy(z, x, 8));
}*/
