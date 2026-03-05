#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	x;
	size_t	ts;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	x = ft_strlen(s2);
	ts = i + x;
	ptr = malloc(ts + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, i);
	ft_memcpy(ptr + i, s2, x + 1);
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, i + 1);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	x;

	if (!s)
		return (NULL);
	x = (unsigned char)c;
	while (*s)
	{
		if (*s == x)
			return ((char *)s);
		s++;
	}
	if (x == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	x;
	char	*c;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start > i)
		return (ft_strdup(""));
	x = i - start;
	if (x < len)
		len = x;
	c = (char *)s + start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, c, len);
	ptr[len] = '\0';
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}