/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:01:54 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/26 23:56:21 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*trim;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (i >= start && ft_strchr(set, s1[i]))
		i--;
	end = i;
	trim = ft_calloc(end - start + 2, sizeof(char));
	if (!trim)
		return (NULL);
	i = start;
	while (i <= end)
	{
		trim[i - start] = s1[i];
		i++;
	}
	return (trim);
}
