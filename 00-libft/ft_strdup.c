/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:49:55 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/15 19:11:40 by tacampos         ###   ########.fr       */
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

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "This is the copy";
	char	*copy1;
	char	*copy2;
   
	copy1 = strdup(src);
	copy2 = ft_strdup(src);

	src[3] = 'a';
	printf("Result_src: %s\n", src);
	printf("Result_strdup: %s\n", copy1);
	printf("Result_ft: %s\n", copy2);
}*/
