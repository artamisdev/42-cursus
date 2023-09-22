/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:08:15 by tacampos          #+#    #+#             */
/*   Updated: 2023/09/22 12:23:34 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
#include <ctype.h>*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int	main(void)
{
	int x;

	x = 222;

	printf("Result: %d\n", ft_isascii(x));
	printf("Result: %d\n", isascii(x));
}*/
