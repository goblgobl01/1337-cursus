/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:07:26 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/03/11 20:40:20 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	top_bottom_walls(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	checking_walls(t_data **data)
{
	int	i;

	if (!top_bottom_walls((*data)->map[0]) || 
		!top_bottom_walls((*data)->map[(*data)->height - 1]))
	{
		write(2, "Error\nwalls error.", 18);
		free_everything(*data);
		exit(1);
	}
	i = 1;
	(*data)->width = ft_strlen((*data)->map[0]);
	while (i < ((*data)->height - 1))
	{
		if ((*data)->map[i][0] != '1' || 
			(*data)->map[i][(*data)->width - 1] != '1')
		{
			write(2, "Error\nwalls error.", 18);
			free_everything(*data);
			exit(1);
		}
		i++;
	}
}

void	locating_player_position(t_data **data)
{
	int	y;
	int	x;

	y = 0;
	while ((*data)->map[y])
	{
		x = 0;
		while ((*data)->map[y][x])
		{
			if ((*data)->map[y][x] == 'P')
			{
				(*data)->px = x;
				(*data)->py = y;
			}
			if ((*data)->map[y][x] == 'E')
			{
				(*data)->ex = x;
				(*data)->ey = y;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(t_data **data, char **strs, int x, int y)
{
	if (strs[y][x] == '1' || strs[y][x] == 'V' || 
		strs[y][x] == 'c' || strs[y][x] == 'e' || strs[y][x] == 'p')
		return ;
	if (strs[y][x] == '0' || strs[y][x] == 'P' || 
		strs[y][x] == 'E' || strs[y][x] == 'C')
	{
		if (strs[y][x] == 'C')
		{
			strs[y][x] = 'c';
			(*data)->ffc++;
		}
		if (strs[y][x] == 'E')
		{
			strs[y][x] = 'e';
			(*data)->ffe++;
		}
		if (strs[y][x] == '0')
			strs[y][x] = 'V';
		if (strs[y][x] == 'P')
			strs[y][x] = 'p';
		flood_fill(data, strs, x + 1, y);
		flood_fill(data, strs, x - 1, y);
		flood_fill(data, strs, x, y + 1);
		flood_fill(data, strs, x, y - 1);
	}
}

void	map_checking(t_data **data)
{
	(*data)->map = ft_split((*data)->big_line, '\n');
	if (!((*data)->map))
	{
		free((*data)->big_line);
		exit(EXIT_FAILURE);
	}
	free((*data)->big_line);
	checking_rows_width(data);
	if ((*data)->collectible < 1 || 
		(*data)->player != 1 || (*data)->exit != 1)
	{
		write(2, "Error\nmust have 1->E, 1->C, 1->P.", 34);
		free_everything(*data);
		exit(1);
	}
	checking_walls(data);
	locating_player_position(data);
	flood_fill(data, (*data)->map, (*data)->px, (*data)->py);
	if ((*data)->ffc != (*data)->collectible || (*data)->ffe != (*data)->exit)
	{
		write(2, "Error\ncollectible or exit not reachable.", 41);
		free_everything(*data);
		exit(1);
	}
}
