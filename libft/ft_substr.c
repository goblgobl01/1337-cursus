/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:21:01 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/11/03 16:49:32 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	s_size;
	char			*p;
	int				length;

	s_size = ft_strlen(s);
	if (start >= s_size)
	{
		p = malloc(1);
		if (p == NULL)
			return (NULL);
		*p = 0;
		return (p);
	}
	length = s_size - start;
	if (s_size - start > len)
		length = len;
	p = malloc(length + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}

// int main()
// {
// 	printf("%zu", sizeof(char));
//     // ft_substr("hello", 4, 40);
// }
