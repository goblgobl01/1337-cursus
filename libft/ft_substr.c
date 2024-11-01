/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:21:01 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/31 20:37:46 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	s_size;
	char			*p;

	s_size = ft_strlen(s);
	if (start >= s_size)
		return (NULL);
	p = malloc(s_size - start + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && (i + start) < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

// int main()
// {
// 	printf("%zu", sizeof(char));
//     // ft_substr("hello", 4, 40);
// }
