/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:27:22 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/11/07 15:12:40 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}

// int main()
// {
// 	char array[] = {101, 102, 103, 0};
// 	printf("im here\n");
// 	ft_memcpy(array, array, 5);
// 	// printf("%s", );
// }

// int main()
// {
// 	char array[] = {-1, 97, 98, 99, 0};
//	char *str = "Hello";
//     char array1[] = {102, 104, 103, 0};
//     // char *ptr = ft_memcpy(array, array1, 10);
// 	char *ptr1 = memcpy(array, array1, 10);
// }