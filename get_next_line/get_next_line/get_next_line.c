#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char *stash;
	static char *buffer;
	char *stash_tmp;
	char *line;
	int read_return;
	int start;

	if(!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		buffer = malloc(BUFFER_SIZE + 1);
		if(!buffer)
			return(free(stash), NULL);
		*stash = 0;
	}

	stash_tmp = stash;
	read_return = 1;
	while(read_return > 0)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if(read_return == -1)
		{
			if(buffer)
			{
				free(buffer);
				buffer = NULL;
			}
			if(stash)
			{
				free(stash);
				stash = NULL;
			}
			return (NULL);
		}
		buffer[read_return] = 0;
		stash = ft_strjoin(stash, buffer);

		// printf("\nthis is the stash: %s\n", stash);
		// printf("===========\n");
		// printf("this is the buffer: %s\n", buffer);
		// printf("===========\n");
		free(stash_tmp);
		stash_tmp = stash;
		// printf("this is the return value : %d", read_return);
		if(ft_strchr(stash, '\n'))
		{
			line = ft_strtrim(stash, "\n");
			start = find_start(stash) + 1;
			stash_tmp = stash;
			stash = ft_strdup(stash+ start);
			free(stash_tmp);
			// printf("this is the stash on the if condition: %s\n", stash);
			// printf("===========\n");
			return (line);
		}
	}
	// printf("\nthis is the stash ath the end: %s\n", stash);
	// printf("\nthis is the return value at the end: %d\n", read_return);
	if(*stash)
	{
		// printf("im here instead\n");
		line = ft_strdup(stash);
		free(stash);
		stash = NULL;
		// printf("this is stash after null: %s\n", stash);
		return (line);
	}
	// printf("im here\n");
	if(stash)
		free(stash);
	if(buffer)
		free(buffer);
	stash = NULL;
	buffer = NULL;
	// printf("sizeof stash: %lu\n", (sizeof(stash) / sizeof(stash[0])));
	// printf("sizeof buffer: %lu\n", (sizeof(buffer) / sizeof(buffer[0])));
	// printf("sizeof stash_tmp: %lu\n", (sizeof(stash_tmp) / sizeof(stash_tmp[0])));
	// printf("sizeof line: %lu\n", (sizeof(line) / sizeof(line[0])));
	return (NULL);
}

int main()
{
	int fd = open("file.txt", O_RDONLY);
	char *buffer = get_next_line(fd);
	printf("%s", buffer);
	free(buffer);
	char *my__ptr = get_next_line(fd);
	printf("%s", my__ptr);
	free(my__ptr);
	while(1);
	return (0);
}

// int main()
// {
// 	_main();
// 	while(1);
// 	return (0);
// }