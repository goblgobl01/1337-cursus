/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:32:12 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/03/15 19:44:19 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_everything(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	if (data->s_img)
		mlx_delete_image(data->mlx, data->s_img);
	if (data->g_img)
		mlx_delete_image(data->mlx, data->g_img);
	if (data->w_img)
		mlx_delete_image(data->mlx, data->w_img);
	if (data->e_img)
		mlx_delete_image(data->mlx, data->e_img);
	if (data)
		free(data);
}

mlx_image_t	*load_texture(t_data *data, char *path)
{
	mlx_texture_t	*png;
	mlx_image_t		*img;

	png = mlx_load_png(path);
	if (!png)
	{
		write(2, "Error\n texture loading", 22);
		free_everything(data);
		exit(1);
	}
	img = mlx_texture_to_image((data->mlx), png);
	if (!img)
	{
		write(2, "Error\n texture loading", 22);
		free_everything(data);
		exit(1);
	}
	mlx_delete_texture(png);
	return (img);
}

void	intializing_images(t_data *data, int flag)
{
	if (flag == 0)
	{
		data->w_img = load_texture(data, "Textures/wall.png");
		data->g_img = load_texture(data, "Textures/ground.png");
		data->s_img = load_texture(data, "Textures/sonic.png");
		data->c_img = load_texture(data, "Textures/collectible.png");
		data->e_img = load_texture(data, "Textures/exit.png");
	}
	else
		data->c_img = load_texture(data, "Textures/collectible.png");
}

int	checking_arguments(char *str)
{
	int		length;
	char	*string;
	int		i;

	length = ft_strlen(str);
	string = "reb.";
	length--;
	i = 0;
	while (i < 4)
	{
		if (str[length] == *string)
		{
			string++;
			length--;
		}
		else
			return (0);
		i++;
	}
	if (str[length] == '/')
		return (0);
	return (1);
}

void	checking_rows_width(t_data **data, int length1, int length2)
{
	if (length1 != length2)
	{
		write(2, "Error\nmap must be rectangular.", 29);
		free((*data)->big_line);
		exit(1);
	}
}
