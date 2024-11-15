/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:33:25 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/11/15 10:34:37 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_function(const char *haystack, size_t *i, const char *needle)
{
	size_t	j;

	j = 0;
	while (haystack[*i] == needle[j] && haystack[*i] && needle[j])
	{
		*i = *i + 1;
		j++;
	}
	return (j);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		remembrance;
	size_t		value;
	const char	*p;

	i = 0;
	if (ft_strlen(needle) == 0 || len < 0)
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			p = &haystack[i];
			remembrance = i;
			value = my_function(haystack, &i, needle);
			if (value == ft_strlen(needle) && i <= len)
				return ((char *)p);
			i = remembrance;
			i++;
		}
		else
			i++;
	}
	return (NULL);
}
