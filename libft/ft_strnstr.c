/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:33:25 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/29 13:13:37 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if(strlen(needle) == 0)
	  return (haystack);
	while(haystack[i] && i < len)
	{
		if(haystack[i] == needle[0])
		{
			p = &haystack[i];
			while(haystack[i] == needle[j] && haystack[i] && needle[i])
			{
				i++;
				j++;
			}
			if (j == strlen(needle))
				return p;
			else
				j = 0;
		}
		else
		  i++;
	}
	return (NULL);
}

// int main()
// {
// 	printf("%s", ft_strnstr("", "abc", 12));
// }