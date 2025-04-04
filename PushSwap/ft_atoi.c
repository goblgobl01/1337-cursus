/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:59:37 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/02/25 16:40:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long long	ft_atoi(const char *str)
{
	long long	result;
	int			sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = sign * -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LONG_MAX - *str - '0') / 10)
				return (LONG_MAX);
		result = result * 10 + *str++ - '0';
	}
	return (result * sign);
}
