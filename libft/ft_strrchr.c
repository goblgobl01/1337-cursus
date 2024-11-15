/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:34:46 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/11/15 10:34:42 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	length;

	length = ft_strlen(s);
	i = 0;
	while (length != -1)
	{
		if (s[length] == (char)c)
			return ((char *)(s + length));
		length--;
	}
	return (NULL);
}
