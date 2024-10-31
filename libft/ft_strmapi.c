/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:41:38 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/30 19:06:54 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		length;
	char	*ptr;

	if(!s || !f)
		return (NULL);
	i = 0;
	length = strlen(s);
	ptr = malloc(length + 1);
	if(ptr == NULL)
		return (NULL);
	while(s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = 0;
	return(ptr);
}
// char fun_32(unsigned int n, char c)
// {
// 	c = c - 32;
// 	return (c);
// }

// int main()
// {
// 	char *str = "abcdefg";
// 	ft_strmapi(str, fun_32);
// }