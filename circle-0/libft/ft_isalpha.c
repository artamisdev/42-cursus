/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:43:18 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/15 18:51:41 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	x;
	int	z;

	x = 'F';
	z = '3';
	printf("Result_ft: %d\n", ft_isalpha(x));
	printf("Result_isalpha: %d\n", isalpha(x));
	printf("\n");
	printf("Result_ft: %d\n", ft_isalpha(z));
	printf("Result_isalpha: %d\n", isalpha(z));
}*/
