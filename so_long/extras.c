/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:32:12 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/03/09 23:55:17 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	intializing_images(t_data *data)
{
	mlx_texture_t	*png;

	png = mlx_load_png("Textures/wall.png");
	data->w_img = mlx_texture_to_image((data->mlx), png);
	free(png);
	png = mlx_load_png("Textures/ground.png");
	data->g_img = mlx_texture_to_image((data->mlx), png);
	free(png);
	png = mlx_load_png("Textures/sonic.png");
	data->s_img = mlx_texture_to_image((data->mlx), png);
	free(png);
	png = mlx_load_png("Textures/collectible.png");
	data->c_img = mlx_texture_to_image((data->mlx), png);
	free(png);
	png = mlx_load_png("Textures/exit.png");
	data->e_img = mlx_texture_to_image((data->mlx), png);
	free(png);
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
