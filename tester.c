// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

// void	*ft_memchr(const void *s, int c, size_t n)
// {
// 	unsigned char	*p;
// 	size_t			i;

// 	p = (unsigned char *)s;
// 	i = 0;
// 	while (i < n)
// 	{
// 		if (i[p] == (unsigned char)c)
// 			return ((void *)(p + i));
// 		i++;
// 	}
// 	return (NULL);
// }

// int main()
// {
// 	printf("%s\n", memchr("", 266, 10));
// 	printf("%s\n", ft_memchr("", 10, 10));
// }

#include <stdio.h>
#include <stdlib.h>
int main()
{
// 	char array[] = {-1, 97, 98, 99, 0};
	char *str = malloc(6);
    // char array1[] = {102, 104, 103, 0};
    // char *ptr = ft_memcpy(array, array1, 10);
// 	char *ptr1 = memcpy(array, array1, 10);
    str[0] = 'H';
    str[1] = 'o';
    str[2] = 'D';
    str[3] = 'a';
    str[4] = 'T';
    str[5] = '\0';
    printf("%s", str);
	pause();
}