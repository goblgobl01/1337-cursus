/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:21:01 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/29 16:08:16 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		s_size;
	char	*p;

	s_size = strlen(s);
	if (start >= s_size)
		return (NULL);
	p = malloc(s_size - start + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s[start + i])
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

// int main()
// {
//     ft_substr("hello", 4, 40);
// }