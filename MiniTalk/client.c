#include "header.h"

void signal_sender(int pid, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;

	// printf("this is  the string :%s", str);
	while(str[i])
	{
		while(j < 8)
		{
			if (((str[i] >> j) & 1) == 1)
			{
				printf("this is 1\n");
				kill(pid, SIGUSR1);
				usleep(1);
			}
			else
			{
				printf("this is 0\n");
				kill(pid, SIGUSR2);
				usleep(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int main(int ac, char **av)
{
	int pid;
	int return_value;

	pid = ft_atoi(av[1]);

	signal_sender(pid, av[2]);
}