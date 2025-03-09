#include "header.h"

int checking_arguments(char *str)
{
	int		length;
	char	*string;
	int		i;

	length = ft_strlen(str);
	string = "reb.";
	length--;
	i = 0;
	while(i < 4)
	{
		if (str[length] == *string)
		{
			string++;
			length--;
		}
		else
			return(0);
		i++;
	}
	if(str[length] == '/')
		return (0);
	return (1);
}
// int	is_valid_character(char c, t_data **all_data)
// {
// 	char	*str;
// 	int		i;

// 	i = 0;
// 	str = "01CEP\n";
// 	if(c == 'C')
// 		(*all_data)->collectible++;
// 	if(c == 'E')
// 		(*all_data)->exit++;
// 	if(c == 'P')
// 		(*all_data)->player++;
// 	while(str[i])
// 	{
// 		if(str[i] == c)
// 			return (1);
// 		i++;
// 	}
// 	return(0);
// }

// int	characters_checking(char *str, t_data **all_data)
// {
// 	int	i;

// 	i = 0;
// 	while(str[i])
// 	{
// 		if(!is_valid_character(str[i], all_data))
// 			return(0);
// 		i++;
// 	}
// 	return(1);
// }

// void	free_strs(char **strs)
// {
// 	int	i;

// 	i = 0;
// 	while (strs[i])
// 	{
// 		free(strs[i]);
// 		i++;
// 	}
// 	free(strs);
// }

// void	checking_rows_width(t_data **all_data)
// {
// 	int	i;

// 	i = 0;
// 	while((*all_data)->strs[i + 1])
// 	{
// 		if(ft_strlen((*all_data)->strs[i]) == ft_strlen((*all_data)->strs[i + 1]))
// 			i++;
// 		else
// 		{
// 			write(2, "Error\nmap must be rectangular.", 29);
// 			free_strs((*all_data)->strs);
// 			exit(0);
// 		}
// 	}
// }

// void	reading_map_file(char *str, t_data **all_data)
// {
// 	char	*ptr;
// 	int		fd;

// 	(*all_data)->height = 0;
// 	fd = open(str, O_RDONLY);
// 	ptr = get_next_line(fd);
// 	(*all_data)->big_line = NULL;
// 	while(ptr)
// 	{
// 		(*all_data)->height++;
// 		(*all_data)->big_line = ft_strjoin((*all_data)->big_line, ptr);
// 		free(ptr);
// 		ptr = get_next_line(fd);
// 	}
// 	close(fd);
// 	(*all_data)->exit = 0;
// 	(*all_data)->player = 0;
// 	(*all_data)->collectible = 0;
// 	if(!characters_checking((*all_data)->big_line, all_data))
// 	{
// 		write(2, "Error\nmap contain invalid character.", 41);
// 		free((*all_data)->big_line);
// 		exit(EXIT_FAILURE);
// 	}
// }

// int	top_bottom_walls(char *str)
// {
// 	int i;

// 	i = 0;
// 	while(str[i])
// 	{
// 		if(str[i] != '1')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// void	checking_walls(t_data **all_data)
// {
// 	int	i;

// 	if(!top_bottom_walls((*all_data)->strs[0]) || 
// 	  !top_bottom_walls((*all_data)->strs[(*all_data)->height - 1]))
// 	{
// 		write(2, "Error\nwalls error.", 18);
// 		free_strs((*all_data)->strs);
// 		exit(0);
// 	}
// 	i = 1;
// 	(*all_data)->width = ft_strlen((*all_data)->strs[0]);
// 	while(i < ((*all_data)->height - 1))
// 	{
// 		if((*all_data)->strs[i][0] != '1' || (*all_data)->strs[i][(*all_data)->width - 1] != '1')
// 		{
// 			write(2, "Error\nwalls error.", 18);
// 			free_strs((*all_data)->strs);
// 			exit(0);
// 		}
// 		i++;
// 	}
// }

// void	locating_player_position(t_data **all_data)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while((*all_data)->strs[y])
// 	{
// 		x = 0;
// 		while((*all_data)->strs[y][x])
// 		{
// 			if((*all_data)->strs[y][x] == 'P')
// 			{
// 				(*all_data)->p_pos_x = x;
// 				(*all_data)->p_pos_y = y;
// 				return ;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	flood_fill(t_data **all_data, char **strs,int x, int y)
// {
// 	if (strs[y][x] == '1' || strs[y][x] == 'V' || strs[y][x] == 'c' || strs[y][x] == 'e' || strs[y][x] == 'p')
// 		return ;
	
// 	if(strs[y][x] == '0' || strs[y][x] == 'P' || strs[y][x] == 'E' || strs[y][x] == 'C')
// 	{
// 		if (strs[y][x] == 'C')
// 		{
// 			strs[y][x] = 'c';
// 			(*all_data)->flood_fille_collectible++;
// 		}
// 		if (strs[y][x] == 'E')
// 		{
// 			strs[y][x] = 'e';
// 			(*all_data)->flood_fille_exit++;
// 		}
// 		if (strs[y][x] == '0')
// 			strs[y][x] = 'V';
// 		if (strs[y][x] == 'P')
// 			strs[y][x] = 'p';
// 		flood_fill(all_data, strs, x + 1, y);
// 		flood_fill(all_data, strs, x - 1, y);
// 		flood_fill(all_data, strs, x, y + 1);
// 		flood_fill(all_data, strs, x, y - 1);
// 	}
// }

// void	map_checking(t_data **all_data)
// {
// 	(*all_data)->strs = ft_split((*all_data)->big_line, '\n');
// 	if(!((*all_data)->strs))
// 	{
// 		free((*all_data)->big_line);
// 		exit(EXIT_FAILURE);
// 	}
// 	free((*all_data)->big_line);
// 	checking_rows_width(all_data);
// 	if((*all_data)->collectible < 1 || (*all_data)->player != 1 || (*all_data)->exit != 1)
// 	{
// 		write(2, "Error\nmust have 1 exit, at least 1 collectible, and 1 start position.", 73);
// 		free_strs((*all_data)->strs);
// 		exit(0);
// 	}
// 	checking_walls(all_data);
// 	locating_player_position(all_data);
// 	(*all_data)->flood_fille_collectible = 0;
// 	(*all_data)->flood_fille_exit = 0;
// 	flood_fill(all_data, (*all_data)->strs, (*all_data)->p_pos_x, (*all_data)->p_pos_y);
// }

// void	intializing_images(t_data *all_data)
// {
// 	mlx_texture_t	*png;

// 	png = mlx_load_png("Textures/wall.png");
// 	all_data->wall_image = mlx_texture_to_image((all_data->mlx), png);
// 	free(png);
// 	png = mlx_load_png("Textures/ground.png");
// 	all_data->ground_image = mlx_texture_to_image((all_data->mlx), png);
// 	free(png);
// 	png = mlx_load_png("Textures/sonic.png");
// 	all_data->sonic_image = mlx_texture_to_image((all_data->mlx), png);
// 	free(png);
// 	png = mlx_load_png("Textures/collectible.png");
// 	all_data->collectible_image = mlx_texture_to_image((all_data->mlx), png);
// 	free(png);
// 	png = mlx_load_png("Textures/exit.png");
// 	all_data->exit_image = mlx_texture_to_image((all_data->mlx), png);
// 	free(png);
// }

// void	draw_map(t_data *all_data)
// {
// 	int	x;
// 	int	y;

// 	intializing_images(all_data);
// 	y = -1;
// 	while(++y < all_data->height)
// 	{
// 		x = -1;
// 		while (++x < all_data->width)
// 		{
// 			if(all_data->strs[y][x] == '1')
// 				mlx_image_to_window((all_data->mlx), all_data->wall_image, 64 * x,  64 * y);
// 			if(all_data->strs[y][x] == 'V')
// 				mlx_image_to_window((all_data->mlx), all_data->ground_image, 64 * x,  64 * y);
// 			if(all_data->strs[y][x] == 'c')
// 			{
// 				mlx_image_to_window((all_data->mlx), all_data->ground_image, 64 * x,  64 * y);
// 				mlx_image_to_window((all_data->mlx), all_data->collectible_image, 64 * x,  64 * y);
// 			}
// 			if(all_data->strs[y][x] == 'p')
// 				mlx_image_to_window((all_data->mlx), all_data->ground_image, 64 * x,  64 * y);
// 			if(all_data->strs[y][x] == 'e')
// 			{
// 				mlx_image_to_window((all_data->mlx), all_data->ground_image, 64 * x,  64 * y);
// 				mlx_image_to_window((all_data->mlx), all_data->exit_image, 64 * x,  64 * y);
// 			}
// 		}
// 	}
// 	mlx_image_to_window((all_data->mlx), all_data->sonic_image, 64 * all_data->p_pos_x,  64 * all_data->p_pos_y);
// }

// void	key_hooks(mlx_key_data_t keydata, void *param)
// {
// 	t_data *all_data;

// 	(void) keydata;
// 	all_data = param;
// 	if (mlx_is_key_down(all_data->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(all_data->mlx);
// 	if (mlx_is_key_down(all_data->mlx, MLX_KEY_UP))
// 		(all_data->sonic_image)->instances[0].y -= 64;
// 	if (mlx_is_key_down(all_data->mlx, MLX_KEY_DOWN))
// 		(all_data->sonic_image)->instances[0].y += 64;
// 	if (mlx_is_key_down(all_data->mlx, MLX_KEY_LEFT))
// 		(all_data->sonic_image)->instances[0].x -= 64;
// 	if (mlx_is_key_down(all_data->mlx, MLX_KEY_RIGHT))
// 		(all_data->sonic_image)->instances[0].x += 64;
// }

// void	all_about_mlx(t_data *all_data)
// {
// 	all_data->mlx = mlx_init(64 * all_data->width, 64 * all_data->height, "MLX42", 0);
// 	if (!(all_data->mlx))
// 		printf("error\n");
// 	draw_map(all_data);
// 	mlx_key_hook(all_data->mlx, key_hooks, all_data);
// 	mlx_loop(all_data->mlx);
// }

int main(int ac, char **av)
{
	t_data	*all_data;
	if (ac != 2 || !checking_arguments(av[1]))
		exit(1);
	// all_data = malloc(sizeof(t_data));
	// if(!all_data)
	// 	exit(0);
	// reading_map_file(av[1], &all_data);
	// map_checking(&all_data);
	// all_about_mlx(all_data);
}