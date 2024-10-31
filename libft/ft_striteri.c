/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:55:18 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/30 19:06:48 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if(!s || !f)
		return (NULL);
	i = 0;
	while(s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// char fun_32(unsigned int n, char *c)
// {
// 	*c = *c - 32;
// 	return (c);
// }

// int main()
// {
// 	char str[7] = "abcdefg";
// 	ft_strmapi(str, fun_32);
// }