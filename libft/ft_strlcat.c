/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:36:59 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/26 16:56:53 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;
	size_t	dest_size;
	size_t	length;

	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	length = ft_strlen(dst);
	if (dstsize < dest_size)
		return (dstsize + src_size);
	else
	{
		i = 0;
		while (length < (dstsize - 1) && src[i])
		{
			dst[length] = src[i];
			i++;
			length++;
		}
		dst[length] = '\0';
		return (dest_size + src_size);
	}
}

// int main(void)
// {
// 	char buffer[20];

// 	// // Test case 1: Normal concatenation within buffer size
// 	// strcpy(buffer, "Hello");
// 	// printf("Result: %zu, Buffer: %s\n", ft_strlcat(buffer, " World", 20), buffer);

// 	// // Test case 2: Concatenation when dstsize is less than dst length
// 	// strcpy(buffer, "12345");
// 	// printf("Result: %zu, Buffer: %s\n", ft_strlcat(buffer, "6789", 5), buffer);

// 	// // Test case 3: Concatenation when dstsize is zero (shouldn't modify dst)
// 	// strcpy(buffer, "Hello");
// 	// printf("Result: %zu, Buffer: %s\n", strlcat(buffer, "There", 0), buffer);

// 	// // Test case 4: src is empty (should return length of dst)
// 	// strcpy(buffer, "Hello");
// 	// printf("Result: %zu, Buffer: %s", strlcat(buffer, "", sizeof(buffer)), buffer);

// 	// Test case 5: dst is empty (should copy src up to dstsize - 1)
// 	strcpy(buffer, "");
// 	printf("Result: %zu, Buffer: %s\n", ft_strlcat(buffer, "Hello", sizeof(buffer)), buffer);
// 	return 0;
// }