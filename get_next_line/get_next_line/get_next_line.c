#include "get_next_line.h"
#include <stdio.h>

char	*read_line(char *stash, int buffer_size, int fd)
{
	char *buffer;
	int read_return;

	buffer = malloc(buffer_size + 1);
	if(!buffer)
		return(free(stash), NULL);

	read_return = 1;
	while(!ft_strchr(stash, '\n') && read_return != 0)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if(read_return < 0)
		{
			if(stash)
				free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[read_return] = 0;
		stash = ft_strjoin(stash, buffer);
	}

	return (free(buffer), stash);
}

char	*get_next_line(int fd)
{
	static char *stash;
	char *tmp;
	char *line;
	int start;

	stash = read_line(stash, BUFFER_SIZE, fd);
	if (!(*stash))
		return (NULL);
	line = ft_strtrim(stash, "\n");
	if(ft_strchr(stash, '\n'))
	{
		start = find_start(stash) + 1;
		tmp = stash;
		stash = ft_strdup(stash + start);
		free(tmp);
	}
	return (line);
}

// int main()
// {
// 	int fd = open("file.txt", O_RDONLY);
// 	char *buffer = get_next_line(fd);
// 	printf("%s", buffer);
// 	free(buffer);
// 	char *my__ptr = get_next_line(fd);
// 	printf("%s", my__ptr);
// 	free(my__ptr);
// 	// char *my_ptr = get_next_line(fd);
// 	// printf("%s", my_ptr);
// 	// free(my_ptr);
// 	while(1);
// 	return (0);
// }

// int main()
// {
// 	_main();
// 	while(1);
// 	return (0);
// }