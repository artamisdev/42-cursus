/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:34:03 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/08 14:59:10 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	const char	a[] = "I'm always hungry";
	const char	b[] = "I'm always hungry";

	printf("Result: %s\n", ft_strrchr(a, 'y'));
	printf("Result: %s\n", strrchr(b, 'y'));
}*/
