/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:18:39 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/25 16:26:59 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * this function is the same as memset the difference
 * is the value that get filled is zero in case of whatever
 * value on memset
*/
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p_b;

	p_b = (char *)s;
	i = 0;
	while (i < n)
		p_b[i++] = 0;
	return (p_b);
}