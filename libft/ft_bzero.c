/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:18:39 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/11/07 15:12:27 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p_b;

	p_b = (unsigned char *)s;
	i = 0;
	while (i < n)
		p_b[i++] = 0;
}

// int main()
// {
// 	char array[] = {101, 102, 103, 0};
// 	printf("im here\n");
// 	ft_bzero(NULL, 0);
// 	// printf("%s", );
// }

/**
 * this function is the same as memset the difference
 * is the value that get filled is zero in case of whatever
 * value on memset
*/
