/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:06:50 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/06 20:14:22 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	chr;

	i = 0;
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

/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	const char	a[] = "All we need is hope";
	const char	b[] = "All we need is hope";

	printf("Result: %s\n", ft_strchr(a, 'h'));
	printf("Result: %s\n", strchr(b, 'h'));
}*/
