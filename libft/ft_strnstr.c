/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:33:25 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/31 13:50:07 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_function(char *haystack, int *i, char *needle, int *j)
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
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return (haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			p = &haystack[i];
			if (my_function(haystack, &i, needle, &j) == ft_strlen(needle))
				return (p);
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
