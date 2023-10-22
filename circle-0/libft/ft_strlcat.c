/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:48:44 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/15 19:13:52 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	i = 0;
	while (src[i] && i < dstsize - dst_len - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char		dst_a[20] = "Primeira";
	const char	src_a[] = "&Segunda";
	char		dst_b[20] = "Primeira";
	const char	src_b[] = "&Segunda";
	
	printf("Result_ft: %zu\n", ft_strlcat(dst_a, src_a, 17));
	printf("Result_strlcat: %zu\n", strlcat(dst_b, src_b, 17));
}*/
