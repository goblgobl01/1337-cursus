/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:51:01 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/29 10:03:00 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *p;
	int i;

	p = (char *)s;
	i = 0;
	while(i < n)
	{
		if(p[i] == c)
			return ((void *) (p + i));
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