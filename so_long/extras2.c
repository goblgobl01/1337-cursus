/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:20:37 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/03/13 20:22:50 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	intializing_all_variables(t_data **data)
{
	(*data)->map = NULL;
	(*data)->big_line = NULL;
	(*data)->s_img = NULL;
	(*data)->g_img = NULL;
	(*data)->w_img = NULL;
	(*data)->c_img = NULL;
	(*data)->e_img = NULL;
	(*data)->mlx = NULL;
	(*data)->exit = 0;
	(*data)->height = 0;
	(*data)->player = 0;
	(*data)->collectible = 0;
	(*data)->ffc = 0;
	(*data)->ffe = 0;
	(*data)->move_count = 0;
}

size_t	str_len(const char *s)
{
	int	i;

	if (!s || !*s)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

void	move_count(t_data *data)
{
	char	*s;

	data->move_count++;
	s = ft_itoa(data->move_count);
	write(2, "move number: ", 13);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	free(s);
}

void	image_to_window(t_data *data, int x, int y, char c)
{
	if (c == '1')
	{
		if (mlx_image_to_window((data->mlx), data->w_img, 64 * x, 64 * y) == -1)
		{
			write(2, "Error\nimage to windows", 23);
			free_everything(data);
			exit(1);
		}
	}
	if (c == 'g')
	{
		if (mlx_image_to_window((data->mlx), data->g_img, 64 * x, 64 * y) == -1)
		{
			write(2, "Error\nimage to windows", 23);
			free_everything(data);
			exit(1);
		}
	}
}

void	draw_collectible(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	mlx_delete_image(data->mlx, data->c_img);
	intializing_images(data, 1);
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (data->map[y][x] == 'c')
			{
				if (mlx_image_to_window((data->mlx), data->c_img, 
						64 * x, 64 * y) == -1)
				{
					write(2, "Error\nimage to windows", 23);
					free_everything(data);
					exit(1);
				}
			}
		}
	}
}
