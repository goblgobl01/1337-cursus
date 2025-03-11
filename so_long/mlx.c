/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:07:20 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/03/11 20:32:32 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	intializing_images(data);
	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (data->map[y][x] == '1')
				mlx_image_to_window((data->mlx), data->w_img, 64 * x, 64 * y);
			if (data->map[y][x] == 'V' || data->map[y][x] == 'p' 
				|| data->map[y][x] == 'e' || data->map[y][x] == 'c')
				mlx_image_to_window((data->mlx), data->g_img, 64 * x, 64 * y);
			if (data->map[y][x] == 'c')
				mlx_image_to_window((data->mlx), data->c_img, 64 * x, 64 * y);
		}
	}
	mlx_image_to_window((data->mlx), data->s_img, 64 * data->px, 64 * data->py);
}

void	draw_collectible(t_data *data)
{
	int				x;
	int				y;
	mlx_texture_t	*png;

	y = -1;
	mlx_delete_image(data->mlx, data->c_img);
	data->c_img = NULL;
	png = mlx_load_png("Textures/collectible.png");
	data->c_img = mlx_texture_to_image((data->mlx), png);
	free(png);
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (data->map[y][x] == 'c')
				mlx_image_to_window((data->mlx), data->c_img, 64 * x, 64 * y);
		}
	}
}

void	collectible_handling(t_data *data, char c)
{
	data->collectible--;
	if (c == 'U')
	{
		data->map[data->py - 1][data->px] = 'V';
		draw_collectible(data);
	}
	else if (c == 'D')
	{
		data->map[data->py + 1][data->px] = 'V';
		draw_collectible(data);
	}
	else if (c == 'L')
	{
		data->map[data->py][data->px -1] = 'V';
		draw_collectible(data);
	}
	else if (c == 'R')
	{
		data->map[data->py][data->px + 1] = 'V';
		draw_collectible(data);
	}
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	(void) keydata;
	data = param;
	if (data->collectible == 0)
		mlx_image_to_window((data->mlx), data->e_img, 64 * (data->ex), 64 * (data->ey));
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE) || ((data->px == data->ex && (data->py == data->ey))))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && data->map[data->py - 1][data->px] != '1')
	{
		if (data->map[data->py - 1][data->px] == 'c')
			collectible_handling(data, 'U');
		(data->s_img)->instances[0].y -= 64;
		data->py--;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && data->map[data->py + 1][data->px] != '1')
	{
		if (data->map[data->py + 1][data->px] == 'c')
			collectible_handling(data, 'D');
		(data->s_img)->instances[0].y += 64;
		data->py++;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && data->map[data->py][data->px - 1] != '1')
	{
		if (data->map[data->py][data->px -1] == 'c')
			collectible_handling(data, 'L');
		(data->s_img)->instances[0].x -= 64;
		data->px--;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) && data->map[data->py][data->px + 1] != '1')
	{
		if (data->map[data->py][data->px + 1] == 'c')
			collectible_handling(data, 'R');
		(data->s_img)->instances[0].x += 64;
		data->px++;
	}
}

void	all_about_mlx(t_data *data)
{
	data->mlx = mlx_init(64 * data->width, 64 * data->height, "MLX42", 0);
	if (!(data->mlx))
	{
		write(2, "Error\ncouldn't initialize mlx", 30);
		free_everything(data);
		exit(1);
	}
	draw_map(data);
	mlx_key_hook(data->mlx, key_hooks, data);
	mlx_loop(data->mlx);
}

