/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:18:43 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/04/21 21:01:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	inside_charset(char c)
{
	char	*charset;
	int		i;

	charset = "|><";
	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(const char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '|' || str[i] == '>' || str[i] == '<')
		{
			if ((str[i] == '>' && str[i + 1] == '>') || (str[i] == '<' && str[i + 1] == '<'))
				i++;
			i++;
			count++;
			continue ;
		}
		if (inside_charset(str[i]))
		{
			i++;
			continue ;
		}
		while (str[i] && !inside_charset(str[i]))
			i++;
		count++;
	}
	return (count);
}

static void	*free_all(char **strs, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static void	*allocate_duplicate(const char *str, int count, char **strs)
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
		if (str[i] == '|' || str[i] == '>' || str[i] == '<')
		{
			if ((str[i] == '>' && str[i + 1] == '>') || (str[i] == '<' && str[i + 1] == '<'))
			{
				if (str[i] == '>')
					strs[k] = ft_strdup(">>");
				if (str[i] == '<')
					strs[k] = ft_strdup("<<");
				i+=2;
				k++;
				continue;
			}
			if (str[i] == '|')
				strs[k] = ft_strdup("|");
			if (str[i] == '>')
				strs[k] = ft_strdup(">");
			if (str[i] == '<')
				strs[k] = ft_strdup("<");
			i++;
			k++;
			continue;
		}
		if (inside_charset(str[i]))
		{
			i++;
			continue ;
		}
		j = i;
		while (str[i] && !inside_charset(str[i]))
			i++;
		strs[k] = malloc((i - j) + 1);
		if (strs[k] == NULL)
			return (free_all(strs, k));
		while (j < i)
			strs[k][l++] = str[j++];
		strs[k++][l] = 0;
		l = 0;
	}
	strs[k] = NULL;
	return ((void *)1);
}


char	**ft_split(char const *s)
{
	char	**strs;
	int		count;

	if (!s)
		return (NULL);
	count = count_words(s);
	strs = malloc(sizeof(char *) * (count + 1));
	if (strs == NULL)
		return (NULL);
	if (!allocate_duplicate(s, count, strs))
		return (NULL);
	return (strs);
}
