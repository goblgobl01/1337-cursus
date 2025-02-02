#include "header.h"


int main(int ac, char **av)
{
	char **strs;
	char **tmp;
	int i;
	int j;

	//av[2] this is the first argument.
	i = 2;
	j = 0;
	while(i < ac)
	{
		tmp = ft_split(av[i], " ");
		while(tmp)
		{
			strs[j] = tmp;
			tmp++;
		}
		i++;
	}

}