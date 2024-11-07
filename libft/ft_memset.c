/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:12:45 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/11/05 13:39:39 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p_b;

	p_b = (unsigned char *)b;
	i = 0;
	while (i < len)
		p_b[i++] = (unsigned char)c;
	return (p_b);
}

// int main()
// {
// 	char array[] = {101, 102, 103, 0};
// 	printf("%s", ft_memset(NULL, 'c', 2));
// }

// int main()
// {
// 	char array[] = {-1, 97, 98, 99};
// 	char ptr = ft_memset(array, 255, 5);

// 	printf("this is the adress : %p\n", &array[0]);
// 	printf("this is the adress : %p\n", &ptr);
// 	printf("%s\n", ptr);
// }
// int	main(void)
// {
// 	char array[100000];
// 	int i;

// 	ft_memset(array, '+', 100000);
// 	i = 0;
// 	while (i < 100000)
// 	{
// 		printf("%c", array[i]);
// 		i++;
// 	}
// }

// /**
//  * memsest funciton tester
//  * this function takes whatever array type and change it to
//  * the given characters type casted to unsigned character to
//  * keep it whithin the ascii codes chracters from 0 to 255
//  * also this function type cast the pointer from whatever type 
//  * to char * type to change each bit of memory bit by bit
// */

// #include <stdio.h>

// int main()
// {
//     char a = -1;            // Assume 8-bit char, -1 is 0xFF
//     unsigned char b = 255;   // 255 is also 0xFF
// // (char)a promotes to int with value -1
// // (unsigned char)b promotes to int with value 255
// if ((unsigned char)a == b) {
//     printf("Equal\n");
// } else {
//     printf("Not equal\n");
// }
// }
