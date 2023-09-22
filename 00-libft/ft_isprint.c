/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:24:31 by tacampos          #+#    #+#             */
/*   Updated: 2023/09/22 12:35:34 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
#include <ctype.h>*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*int	main(void)
{
	int	x;

	x = 32;

	printf("Result: %d\n", ft_isprint(x));
	printf("Result: %d\n", isprint(x));

}*/
