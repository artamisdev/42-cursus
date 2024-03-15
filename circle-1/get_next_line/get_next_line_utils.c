#include "get_next_line.h"
// 1. Crear estas funciones: 

// stchr okayy

int	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		++i;
	}
	return (0);
}
// strdup okay

char	*ft_strdup(const char *s1)
{
    int		i;
	char	*cpy;

	i = 0;
	while (s1[i] != '\0')
		i++;
	cpy = malloc((i + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	return (cpy);
}

// confirmar se esta funcionando bem, tirar strlcat
char	*ft_strjoin(char *s1, char *buff)
{
	int		size;
	int		size_s1;
	char	*join;

    if (!s1)
    {
        s1 = malloc(sizeof(char));
        s1[0] = '\0';
    }
    if(!s1 || !buff)
        return (NULL);
	size_s1 = ft_strlen(s1);
	size = size_s1 + ft_strlen(buff);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(buff) + 1));
	if (!join)
		return (NULL);
	ft_strlcat(join, s1, size_s1 + 1);
	ft_strlcat(join, buff, size + 1);
	return (join);
}
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	i = 0;
	while (src[i] && i < dstsize - dst_len - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
// tudo certo

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