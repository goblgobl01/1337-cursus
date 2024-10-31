/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:13:36 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/10/31 11:58:17 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strdup(char *src)
{
	int		length;
	int		i;
	char	*p;

	length = strlen(src);
	p = malloc(length + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = 0;
	return (p);
}
