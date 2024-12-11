#include "ft_printf.h"

int main()
{
	printf("\n%d\n: ", ft_printf("%p", (void *)-14523));
	printf("\n%d\n: ", printf("%p", (void *)-14523));
	return (0);
}