#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libft.h"

int	my_count_words(const char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			continue ;
		}
		while (str[i] && !(str[i] == c))
			i++;
		count++;
	}
	return (count);
}

void	allocate_duplicate(const char *str, char c, int count, char **strs)
{
	int	i;
	int	j;
	int	k;
	int	l;

	l = 0;
	k = 0;
	i = 0;
	while (k < count)
	{
		if (str[i] == c)
		{
			i++;
			continue ;
		}
		j = i;
		while (str[i] && !(str[i] == c))
			i++;
		strs[k] = malloc((i - j) + 1);
		while (j < i)
			strs[k][l++] = str[j++];
		strs[k++][l] = 0;
		l = 0;
	}
	strs[k] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		count;

	count = my_count_words(s, c);
	strs = malloc(sizeof(char *) * (count + 1));
	if (strs == NULL)
		return (NULL);
	allocate_duplicate(s, c, count, strs);
	return (strs);
}

int main()
{
	// printf("%zu", sizeof(char));
	printf("%s", ft_substr("hello", 4, 0));
}
