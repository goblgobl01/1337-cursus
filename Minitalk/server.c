/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:17:36 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/03/24 00:26:14 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

pid_t	g_clinet_pid = 0;

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;

	(void)context;
	if (info->si_pid != g_clinet_pid)
	{
		g_clinet_pid = info->si_pid;
		c = 0;
		i = 0;
	}
	c = c << 1;
	if (sig == SIGUSR1)
		c = c | 1;
	if (sig == SIGUSR2)
		c = c | 0;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	char				*str;
	struct sigaction	sig;

	sig.sa_sigaction = signal_handler;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	pid = getpid();
	str = ft_itoa(pid);
	write(1, "pid: ", 5);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	while (1)
		pause();
}
