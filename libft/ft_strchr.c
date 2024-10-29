/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:22:23 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/26 19:07:52 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;
	
	i = 0;
	while(s[i])
	{
		if(s[i] == c)
			return ((char *) (s + i));
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	char buffer[] = "hello";
// 	printf("%s", ft_strchr(buffer, 'f'));
// }