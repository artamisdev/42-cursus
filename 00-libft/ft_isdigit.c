/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:25:37 by tacampos          #+#    #+#             */
/*   Updated: 2023/09/14 19:52:13 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
#include <ctype.h>*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*int	main(void)
{
	int	a;
	int	b;

	a = '5';
	b = '$';
	printf("Result ft_isdigit: %d\n", ft_isdigit(a));
	printf("Result ft_isdigit: %d\n", ft_isdigit(b));
	printf("Result isdigit: %d\n", isdigit(a));
	printf("Result isdigit: %d\n", isdigit(b));
}*/
