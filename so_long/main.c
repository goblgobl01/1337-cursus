/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:06:31 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/03/24 01:23:12 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_valid_character(char c, t_data **data)
{
	char	*str;
	int		i;

	i = 0;
	str = "01CEP\n";
	if (c == 'C')
		(*data)->collectible++;
	if (c == 'E')
		(*data)->exit++;
	if (c == 'P')
		(*data)->player++;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	characters_checking(char *str, t_data **data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_valid_character(str[i], data))
			return (0);
		i++;
	}
	if (str[i - 1] == '\n')
		return (0);
	return (1);
}

void	reading_map_file(char *str, t_data **data)
{
	char	*ptr;
	int		fd;
	int		length;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\n", 6), free(data), exit(1), (void)0);
	ptr = get_next_line(fd);
	length = str_len(ptr);
	while (ptr)
	{
		(*data)->height++;
		(*data)->big_line = ft_strjoin((*data)->big_line, ptr);
		free(ptr);
		ptr = get_next_line(fd);
		if (!ptr)
			break ;
		checking_rows_width(data, length, str_len(ptr));
		length = str_len(ptr);
	}
	close(fd);
	if (!characters_checking((*data)->big_line, data))
		return (write(2, "Error\n", 6), free((*data)->big_line), 
			free(data), exit(1), (void)0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2 || !checking_arguments(av[1]))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	data = malloc(sizeof(t_data));
	if (!data)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	intializing_all_variables(&data);
	reading_map_file(av[1], &data);
	map_checking(&data);
	all_about_mlx(data);
	mlx_terminate(data->mlx);
	free_everything(data);
	exit(0);
}
