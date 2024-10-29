#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	char *p;
	int i;

	p = malloc(count * size);
	if(p == NULL)
		return (NULL);
	while(i < count * size)
	{
		p[i] = 0;
		i++;
	}
	return ((void *) p);
}

int main()
{
	int i;
	int *p = ft_calloc(4, 4);
	i = 0;

	while(i < 4)
	{
		printf("%d\n", p[i]);
	}
}