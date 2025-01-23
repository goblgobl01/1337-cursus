#include "header.h"

void signal_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		printf("i have received SIGUSR1 signal\n");
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

	pid = getpid();

	printf("this is my pid: %d\n", pid);
	pause();
}