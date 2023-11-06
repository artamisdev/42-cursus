/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:31:42 by tacampos          #+#    #+#             */
/*   Updated: 2023/11/06 16:36:24 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapped;
	int		size;
	int		i;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	mapped = ft_calloc(size + 1, sizeof(char));
	if (!mapped)
		return (NULL);
	i = 0;
	while (i < size)
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	return (mapped);
}
