/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:39:22 by tacampos          #+#    #+#             */
/*   Updated: 2023/09/26 17:18:27 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
#include <string.h>*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest;
	const char	*source;

	if (!dst && !src)
		return (0);
	dest = dst;
	source = src;
	if (dest > source)
	{
		while (len--)
			dest[len] = source[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}

/*int main(void)
{
	char	i[] = "Primeira";
	char	j[] = "Segunda";
	char	x[] = "Primeira";
	char	z[] = "Segunda";
	
	printf("Result: %s\n", ft_memmove(i, j, 9));
	printf("Result: %s\n", memmove(x, z, 9));

}*/
