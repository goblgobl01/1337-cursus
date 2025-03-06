#ifndef HEADER_H
#define HEADER_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"


typedef struct s_struct
{
	char	**strs;
	char	*big_line;
	int		collectible;
	int		exit;
	int		player;
	int		line_count;
	int		p_pos_x;
	int		p_pos_y;
	int		flood_fille_exit;
	int		flood_fille_collectible;
}t_data;

char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);

#endif