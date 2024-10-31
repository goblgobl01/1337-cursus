/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:20:04 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/26 18:10:20 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	if (dstsize > 0)
	{
		while ((i < (dstsize - 1)) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return ((unsigned int)ft_strlen(src));
}

// int main()
// {
// 	char dest[] = "he";
// 	char source[] = "hihello";
// 	int retur;

// 	retur = strlcpy(dest, source, 1);
// 	printf("this is the string: \"%s\",
// this the return (value: %d", dest, retur));
// }