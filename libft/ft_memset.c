/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:12:45 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/25 21:21:05 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*p_b;

	p_b = (char *)b;
	i = 0;
	while (i < len)
		p_b[i++] = (unsigned char)c;
	return (p_b);
}

/**
 * memsest funciton tester
 * this function takes whatever array type and change it to
 * the given characters type casted to unsigned character to
 * keep it whithin the ascii codes chracters from 0 to 255
 * also this function type cast the pointer from whatever type 
 * to char * type to change each bit of memory bit by bit
*/
int main()
{
	char array[100000];
	int i;

	ft_memset(array, '+', 100000);
	i = 0;
	while(i < 100000)
	{
		printf("%c", array[i]);
		i++;
	}
}