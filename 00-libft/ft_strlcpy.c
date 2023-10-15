/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:23:35 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/15 19:15:08 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	size_t			src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char	i[] = "Primeira";
	char	j[] = "Segunda";
	char	x[] = "Primeira";
	char	z[] = "Segunda";

	printf("Result_ft: %lu\n", ft_strlcpy(i, j, 4));
	printf("Result_strlcpy: %zu\n", strlcpy(x, z, 4));
}*/
