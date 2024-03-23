#include "get_next_line.h"

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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest;
	const char	*source;

	if (!dst && !src)
		return (0);
	dest = dst;
	source = src;
	if (dest > source)
	{
		while (len--)
			dest[len] = source[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}

char	*ft_strjoin(char *stash, char *buff)
{
	int		i;
	int		j;
	char	*str;

	if (!stash)
	{
		stash = malloc(sizeof(char));
		stash[0] = '\0';
	}
	if (!stash || !buff)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buff) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (stash[++i])
		str[i] = stash[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[i] = '\0';
	return (str);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
