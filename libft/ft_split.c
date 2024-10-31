/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:18:43 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/31 10:47:12 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_words(char *str, char c)
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

void	allocate_duplicate(char *str, char c, int count, char **strs)
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

char	**ft_split(char *str, char c)
{
	char	**strs;
	int		count;

	count = count_words(str, c);
	strs = malloc(sizeof(char *) * (count + 1));
	if (strs == NULL)
		return (NULL);
	allocate_duplicate(str, c, count, strs);
	return (strs);
}

// int main()
// {
//     char **ptr = ft_split("*", '*');
//     printf("%s", *ptr);
// }