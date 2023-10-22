/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:29:44 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/15 19:32:48 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	i;
	int	j;

	i = 'A';
	j = 'A';
	printf("Result_ft: %c\n", ft_tolower(i));
	printf("Result_tolower: %c\n", tolower(j));
}*/
