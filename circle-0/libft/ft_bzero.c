/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:15:48 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/15 18:38:03 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	i[] = "Galera de cowboy";
	char	j[] = "Galera de cowboy";

	ft_bzero(i+3, 5);
	printf("Result: %s\n", i);

	bzero(j+3, 5);
	printf("Result: %s\n", j);
}*/
