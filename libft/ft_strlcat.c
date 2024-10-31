/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:36:59 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/31 13:49:52 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
