/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:56:33 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/15 18:43:43 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int i;
	int j;
	int	x;
	int z;

	i = '%';
	j = '6';
	x = 'e';
	z = 'A';

	printf("Result: %d\n", isalnum(i));
	printf("Result: %d\n", isalnum(j));
	printf("Result: %d\n", isalnum(x));
	printf("Result: %d\n", isalnum(z));
	printf("Result: %d\n", ft_isalnum(i));
	printf("Result: %d\n", ft_isalnum(j));
	printf("Result: %d\n", ft_isalnum(x));
	printf("Result: %d\n", ft_isalnum(z));

}*/
