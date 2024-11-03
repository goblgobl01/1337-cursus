/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:48:59 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/11/03 17:13:18 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;
	int		i;

	if (!dst && !src)
		return (NULL);
	dest = (char *)dst;
	source = (char *)src;
	if (dest > source)
	{
		i = len - 1;
		while (i != -1)
		{
			dest[i] = source[i];
			i--;
		}
		return (dest);
	}
	i = 0;
	while ((size_t)i < len)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char data[] = "HelloWor";
// 	char data2[] = "My name is";

// 	ft_memmove(data, data2, 10);

// 	printf("Result with memcpy: %s\n", data);

// 	return (0);
// }
