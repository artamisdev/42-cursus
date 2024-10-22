/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:19:23 by tacampos          #+#    #+#             */
/*   Updated: 2024/10/22 20:00:29 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countwords(char const *str, char c)
{
	int		i;
	size_t	count;

	i = 0;
	if (!str[i])
		return (0);
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static int	count_valid_chars(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	free_parts(char **parts, int j)
{
	while (j--)
		free(parts[j]);
	free(parts);
}

static char	**fill_parts(char **parts, const char *str, char c)
{
	int		i;
	int		j;
	int		valid_char_count;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		valid_char_count = count_valid_chars(&str[i], c);
		if (valid_char_count > 0)
		{
			parts[j] = ft_substr(str, i, valid_char_count);
			if (!parts[j])
			{
				free_parts(parts, j);
				return (NULL);
			}
			j++;
		}
		while (str[i] && str[i] != c)
			i++;
	}
	return (parts);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words_count;

	words_count = countwords(s, c);
	split = ft_calloc(words_count + 1, sizeof (char *));
	if (!split)
		return (NULL);
	split = fill_parts(split, s, c);
	return (split);
}
