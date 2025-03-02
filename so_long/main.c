#include "header.h"

int checking_arguments(char *str)
{
	
}

int main(int ac, char **av)
{
	if (ac != 2 || !checking_arguments(av[1]))
		exit(0);
}