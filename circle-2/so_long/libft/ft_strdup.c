/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:49:55 by tacampos          #+#    #+#             */
/*   Updated: 2024/10/22 20:00:25 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	int		src_len;
	char	*cpy;

	src_len = ft_strlen(s1);
	cpy = malloc((src_len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	ft_strcpy(cpy, (char *)s1);
	return (cpy);
}
