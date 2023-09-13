/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:43:18 by tacampos          #+#    #+#             */
/*   Updated: 2023/09/13 19:59:25 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	int	x;
	int	z;

	x = 'F';
	z = '3';
	printf("Result 1: %d\n", ft_isalpha(x));
	printf("Result 2: %d", ft_isalpha(z));
	printf("\n");
}*/
