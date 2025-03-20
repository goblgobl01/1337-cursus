/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:07:20 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/03/12 23:29:34 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (data->map[y][x] == '1')
				image_to_window(data, x, y, '1');
			if (data->map[y][x] == 'V' || data->map[y][x] == 'p' 
				|| data->map[y][x] == 'e' || data->map[y][x] == 'c')
				image_to_window(data, x, y, 'g');
		}
	}
	draw_map_rest(data);
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

void	move_player(t_data *data, char c)
{
	const char	directions[] = {'U', 'D', 'L', 'R'};
	const int	dx[] = {0, 0, -1, 1};
	const int	dy[] = {-1, 1, 0, 0};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (c == directions[i])
		{
			if (data->map[data->py + dy[i]][data->px + dx[i]] == 'c')
				collectible_handling(data, c);
			(data->s_img)->instances[0].x += dx[i] * 64;
			(data->s_img)->instances[0].y += dy[i] * 64;
			data->px += dx[i];
			data->py += dy[i];
			break ;
		}
		i++;
	}
	move_count(data);
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	(void) keydata;
	data = param;
	if (data->collectible == 0)
		data->e_img->instances[0].enabled = true;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE) || 
		(((data->px == data->ex && 
					(data->py == data->ey))) && data->collectible == 0))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && 
		data->map[data->py - 1][data->px] != '1')
		move_player(data, 'U');
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && 
		data->map[data->py + 1][data->px] != '1')
		move_player(data, 'D');
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && 
		data->map[data->py][data->px - 1] != '1')
		move_player(data, 'L');
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) && 
		data->map[data->py][data->px + 1] != '1')
		move_player(data, 'R');
}

void	all_about_mlx(t_data *data)
{
	if (data->height > 22 || data->width > 40)
	{
		write(2, "Error\nmap too big", 18);
		free_everything(data);
		exit(1);
	}
	data->mlx = mlx_init(64 * data->width, 64 * data->height, "MLX42", 0); 
	if (!(data->mlx))
	{
		write(2, "Error\ncouldn't initialize mlx", 30);
		free_everything(data);
		exit(1);
	}
	intializing_images(data, 0);
	draw_map(data);
	mlx_key_hook(data->mlx, key_hooks, data);
	mlx_loop(data->mlx);
}
