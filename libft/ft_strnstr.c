/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:33:25 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/31 20:24:53 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_function(const char *haystack, size_t *i, const char *needle, size_t *j)
{
	while (haystack[*i] == needle[*j] && haystack[*i] && needle[*j])
	{
		*i = *i + 1;
		*j = *j + 1;
	}
	return (*j);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		value;
	const char	*p;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			p = &haystack[i];
			value = my_function(haystack, &i, needle, &j);
			if (value == ft_strlen(needle))
				return ((char *)p);
			else
				j = 0;
		}
		else
			i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	printf("%s", ft_strnstr("", "abc", 12));
// }
