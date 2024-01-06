/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:34:03 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/25 17:45:24 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	int		str_len;
	char	chr;

	str = (char *)s;
	str_len = ft_strlen(str);
	chr = c;
	if (chr == '\0')
		return (&str[str_len]);
	i = str_len;
	while (i > 0)
	{
		i--;
		if (str[i] == chr)
			return (&str[i]);
	}
	return (NULL);
}
