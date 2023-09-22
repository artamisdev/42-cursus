/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:56:33 by tacampos          #+#    #+#             */
/*   Updated: 2023/09/22 11:58:59 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
#include <ctype.h>*/

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/*int	main(void)
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
