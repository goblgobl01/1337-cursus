#include "get_next_line.h"

static char	*ft_strcat(char *dest, const char *src)
{
	int	length_dest;
	int	i;

	i = 0;
	length_dest = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[length_dest + i] = src[i];
		i++;
	}
	dest[length_dest + i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}


char	*ft_strjoin(char  *s1, char  *s2)
{
	int		length;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(length + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	find_start(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != '\n')
		{
			i++;
			continue ;
		}
		else
			break ;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		length;
	int		i;
	char	*p;

	length = ft_strlen(src);
	p = malloc(length + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		length;
	int		i;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = find_start(s1);
	length = end - start;
	if (start > end)
		return (ft_strdup(""));
	ptr = malloc(length + 2);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		ptr[i++] = s1[start++];
	ptr[i] = 0;
	return (ptr);
}
