/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:51:01 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/11/03 13:14:06 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	int i = 0;
// 	int array[] = {900, 500, 244, 3, 4};
// 	int *another_array = memchr(array, 500, 5);

// 	while(i < 3)
// 	{
// 		printf("%d\n", another_array[i]);
// 		i++;
// 	}
// }
