/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:53:38 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/31 13:49:16 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;
	int				i;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	i = 0;
	if (n > 0)
	{
		n = n - 1;
		while (i <= n)
		{
			if (p_s1[i] == p_s2[i])
				i++;
			else
			{
				return (p_s1[i] - p_s2[i]);
				break ;
			}
		}
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// void test_ft_memcmp(const void *s1, const void *s2, size_t n, int expected)
// {
//     int result = ft_memcmp(s1, s2, n);
//     printf("ft_memcmp(%s, %s, %zu) = %d | Expected: %d | %s\n",
//            (const char *)s1, (const char *)s2, n, result, expected,
//            result == expected ? "PASS" : "FAIL");
// }

// int main()
// {
//     // Case 1: Identical strings
//     test_ft_memcmp("abc", "abc", 3, 0);

//     // Case 2: Different strings (first byte differs)
//     test_ft_memcmp("abc", "xbc", 3, 'a' - 'x');

//     // Case 3: Different strings (last byte differs)
//     test_ft_memcmp("abc", "abd", 3, 'c' - 'd');

//     // Case 4: Same prefix, n is shorter than the length of strings
//     test_ft_memcmp("abcdef", "abcxyz", 3, 0);

//     // Case 5: Different length strings, where comparison is limited by `n`
//     test_ft_memcmp("abc", "abcdef", 3, 0);

//     // Case 6: Comparison stops before `\0`
//     test_ft_memcmp("abc", "abc\0xyz", 5, 0);

//     // Case 7: `n` is zero
//     test_ft_memcmp("abc", "xyz", 0, 0);

//     return (0);
// }
