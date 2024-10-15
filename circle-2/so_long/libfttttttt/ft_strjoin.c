/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:04:24 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/25 21:49:15 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		size_s1;
	char	*join;

	size_s1 = ft_strlen(s1);
	size = size_s1 + ft_strlen(s2);
	join = ft_calloc((size + 1), sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcat(join, s1, size_s1 + 1);
	ft_strlcat(join, s2, size + 1);
	return (join);
}
