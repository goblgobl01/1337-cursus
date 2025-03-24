/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:15:27 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/03/23 23:40:43 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	signal_sender(int pid, char *str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 7;
	while (str[i])
	{
		while (j >= 0)
		{
			if (((str[i] >> j) & 1) == 1)
				flag = kill(pid, SIGUSR1);
			else
				flag = kill(pid, SIGUSR2);
			if (flag)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			usleep(400);
			j--;
		}
		j = 7;
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 2)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		signal_sender(pid, av[2]);
	}
	else
		write(2, "Error\nusage: <./client> <pid> <string>", 39);
	return (0);
}
