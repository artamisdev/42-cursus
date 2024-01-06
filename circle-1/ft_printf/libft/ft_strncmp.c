/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:03:27 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/25 17:31:33 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
