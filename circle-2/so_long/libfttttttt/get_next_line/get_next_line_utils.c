/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:53:49 by tacampos          #+#    #+#             */
/*   Updated: 2024/10/15 20:35:17 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	chr;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)s;
	chr = c;
	while (str[i])
	{
		if (str[i] == chr)
			return (&str[i]);
		i++;
	}
	if (chr == '\0')
		return (&str[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	i;

	if (s == 0)
		return (0);
	i = ft_strlen(s);
	if (start >= i)
	{
		new_string = ft_calloc(1, 1);
		return (new_string);
	}
	else if (i - start < len)
		new_string = ft_calloc((i - start) + 1, 1);
	else
		new_string = ft_calloc(len + 1, 1);
	if (new_string == 0)
		return (0);
	i = 0;
	while (i < len && s[start])
		new_string[i++] = s[start++];
	return (new_string);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_s1;
	int		size_s2;
	char	*str;
	int		i;
	int		j;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str = ft_calloc((size_s1 + size_s2 + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size_s1)
		str[i++] = s1[j++];
	j = 0;
	while (j < size_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*allocated;
	size_t	i;
	char	*change;

	allocated = malloc(count * size);
	if (!allocated)
		return (NULL);
	change = (char *)allocated;
	i = 0;
	while (i < count * size)
	{
		change[i] = 0;
		i++;
	}
	return ((void *)change);
}
