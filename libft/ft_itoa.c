/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:52:01 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/30 16:48:50 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int count_words(int n)
{
	int i;

	i = 1;
	while((n = n / 10) != 0)
		i++;
	return i;
}

void string_filler_3000(char *ptr, long int n, int count)
{
	int i;
	
	i = 0;
	if(n == 0)
	{
		ptr[i] = (n % 10) + '0';
		i++;
	}
	if(n < 0)
	{
		n = -n;
		ptr[0] = '-';
		i++;
	}
	while(n != 0)
	{
		ptr[count - 1] = (n % 10) + '0';
		n = n / 10;
		count--;
		i++;
	}
	ptr[i] = 0;
}

char *ft_itoa(int n)
{
	int		count;
	char	*ptr;

	count = count_words(n);
	if(n < 0)
		count++;

	ptr = malloc(count + 1);
	if(ptr == NULL)
		return (NULL);
	string_filler_3000(ptr, n, count);
	return (ptr);
}

// int main()
// {
// 	printf("%s", ft_itoa(-2147483648));
// 	return (0);
// }