/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:34:46 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/26 18:39:33 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int length;

	length = strlen(s) - 1;
	i = 0;
	while(length != -1)
	{
		if(s[length] == c)
			return ((char *) (s + length));
		length--;
	}
	return (NULL);
}

// int main()
// {
// 	char buffer[] = "hello";
// 	printf("%s", ft_strchr(buffer, 'f'));
// }