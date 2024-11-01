/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:17:17 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/31 19:26:10 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
		i++;
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}

// int	main(void)
// {
// 	int i;
// 	int *p = ft_calloc(4, 4);
// 	i = 0;

// 	while (i < 4)
// 	{
// 		printf("%d\n", p[i]);
// 	}
// }
