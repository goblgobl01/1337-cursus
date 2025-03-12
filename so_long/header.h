/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:53:24 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/03/12 19:56:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "MLX/include/MLX42/MLX42.h"

typedef struct s_struct
{
	char		**map;
	char		*big_line;
	int			collectible;
	int			exit;
	int			player;
	int			height;
	int			width;
	int			px;
	int			py;
	int			ffe;
	int			ffc;
	int			ex;
	int			ey;
	// mlx_image_t	*s_img;
	// mlx_image_t	*g_img;
	// mlx_image_t	*w_img;
	// mlx_image_t	*c_img;
	// mlx_image_t	*e_img;
	// mlx_t		*mlx;

}t_data;

char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
void	all_about_mlx(t_data *data);
void	map_checking(t_data **data);
void	intializing_images(t_data *data);
int		checking_arguments(char *str);
void	checking_rows_width(t_data **data, int length1, int length2);
void	free_everything(t_data *data);
void	intializing_all_variables(t_data **data);

#endif