/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:32:12 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/03/12 20:03:57 by codespace        ###   ########.fr       */
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
	// if (data->s_img)
	// 	mlx_delete_image(data->mlx, data->s_img);
	// if (data->g_img)
	// 	mlx_delete_image(data->mlx, data->g_img);
	// if (data->w_img)
	// 	mlx_delete_image(data->mlx, data->w_img);
	// if (data->e_img)
	// 	mlx_delete_image(data->mlx, data->e_img);
	if (data)
		free(data);
}

// void	intializing_images(t_data *data)
// {
// 	mlx_texture_t	*png;

// 	png = mlx_load_png("Textures/wall.png");
// 	data->w_img = mlx_texture_to_image((data->mlx), png);
// 	mlx_delete_texture(png);
// 	png = mlx_load_png("Textures/ground.png");
// 	data->g_img = mlx_texture_to_image((data->mlx), png);
// 	mlx_delete_texture(png);
// 	png = mlx_load_png("Textures/sonic.png");
// 	data->s_img = mlx_texture_to_image((data->mlx), png);
// 	mlx_delete_texture(png);
// 	png = mlx_load_png("Textures/collectible.png");
// 	data->c_img = mlx_texture_to_image((data->mlx), png);
// 	mlx_delete_texture(png);
// 	png = mlx_load_png("Textures/exit.png");
// 	data->e_img = mlx_texture_to_image((data->mlx), png);
// 	mlx_delete_texture(png);
// }

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

void	intializing_all_variables(t_data **data)
{
	(*data)->map = NULL;
	(*data)->big_line = NULL;
	// (*data)->s_img = NULL;
	// (*data)->g_img = NULL;
	// (*data)->w_img = NULL;
	// (*data)->c_img = NULL;
	// (*data)->e_img = NULL;
	// (*data)->mlx = NULL;
	(*data)->exit = 0;
	(*data)->player = 0;
	(*data)->collectible = 0;
	(*data)->ffc = 0;
	(*data)->ffe = 0;
}
