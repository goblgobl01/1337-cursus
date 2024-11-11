/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:21:01 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/11/08 10:40:09 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	s_size;
	char			*p;
	int				length;

	if (!s)
		return (NULL);
	s_size = ft_strlen(s);
	if (start >= s_size)
		return (ft_strdup(""));
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
// 	printf("hello again\n");
// 	ft_substr(NULL, 4, 40);
// }
