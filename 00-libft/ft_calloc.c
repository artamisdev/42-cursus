/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:59:26 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/15 18:41:09 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*allocated;

	allocated = malloc(count * size);
	if (!allocated)
		return (NULL);
	ft_bzero(allocated, size * count);
	return (allocated);
}

/*#include <stdio.h>

int	main(void)
{
	char	*str = ft_calloc(6, sizeof(char));

	str[0] = 'e';
	str[1] = 'i';
	str[2] = 't';
	str[3] = 'a';

	printf("Result_Calloc: \"%s\"\n", str);
}*/
