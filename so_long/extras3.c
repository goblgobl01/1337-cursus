/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:29:38 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/03/13 20:12:58 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_map_rest(t_data *data)
{
	draw_collectible(data);
	if (mlx_image_to_window((data->mlx), data->s_img, 64 
			* data->px, 64 * data->py) == -1 || 
		mlx_image_to_window((data->mlx), data->e_img, 64 
			* data->ex, 64 * data->ey) == -1)
	{
		write(2, "Error\ndraw_map", 15);
		free_everything(data);
		exit(1);
	}
	data->e_img->instances[0].enabled = false;
}
