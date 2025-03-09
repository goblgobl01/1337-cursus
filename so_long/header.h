#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "MLX/include/MLX42/MLX42.h"


typedef struct s_struct
{
	char		**strs;
	char		*big_line;
	int			collectible;
	int			exit;
	int			player;
	int			height;
	int			width;
	int			p_pos_x;
	int			p_pos_y;
	int			flood_fille_exit;
	int			flood_fille_collectible;
	mlx_image_t	*sonic_image;
	mlx_image_t	*ground_image;
	mlx_image_t	*wall_image;
	mlx_image_t	*collectible_image;
	mlx_image_t	*exit_image;
	mlx_t		*mlx;

}t_data;

char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);

#endif