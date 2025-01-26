#include "header.h"

void	signal_handler(int sig)
{
	static char c;
	static int i;

	c = c << 1;
	if(sig == SIGUSR1)
		c = c | 1;
	if(sig == SIGUSR2)
		c = c | 0;
	i++;

	if(i == 8)
	{
		printf("%c", c);
		i = 0;
		c = 0;
	}
}

int main()
{
	pid_t pid;
	struct sigaction sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	if(sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	if(sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	pid = getpid(); 

	printf("this is my pid: %d\n", pid);
	while (1)
		pause();
}