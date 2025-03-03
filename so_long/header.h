#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"


typedef struct s_struct
{
	char	**strs;
	int		collectible;
	int		exit;
	int		player;
	int		line_count;
}t_data;

char	*get_next_line(int fd);

#endif