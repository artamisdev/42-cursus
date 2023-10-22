/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:33:31 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/15 19:01:39 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char	i[] = "you got this!";
	
	printf("Result_ft: %s\n", ft_memset(i, 'H', 6));
	printf("Result_memset: %s\n", memset(i, 'H', 6));
}*/
