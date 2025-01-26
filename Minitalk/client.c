#include "header.h"

void signal_sender(int pid, char *str)
{
	int i;
	int j;

	i = 0;
	j = 7;

	while(str[i])
	{
		while(j >= 0)
		{
			if (((str[i] >> j) & 1) == 1)
			{
				kill(pid, SIGUSR1);
				usleep(500);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(500);
			}
			j--;
		}
		j = 7;
		i++;
	}
}

int main(int ac, char **av)
{
	int pid;
	(void)ac;

	pid = ft_atoi(av[1]);

	signal_sender(pid, av[2]);
}