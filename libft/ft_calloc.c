/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:17:17 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/31 11:51:15 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	int		i;

	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
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