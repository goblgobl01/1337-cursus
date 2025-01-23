#include "header.h"


int main(int ac, char **av)
{
	int pid;
	int return_value;

	pid = ft_atoi(av[1]);

	return_value = kill(pid, SIGUSR1);
	printf("this is the return value: %d\n", return_value);
}