/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:06:31 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/03/11 20:57:29 by codespace        ###   ########.fr       */
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
	return (1);
}

void	reading_map_file(char *str, t_data **data)
{
	char	*ptr;
	int		fd;

	(*data)->height = 0;
	fd = open(str, O_RDONLY);
	ptr = get_next_line(fd);
	(*data)->big_line = NULL;
	while (ptr)
	{
		(*data)->height++;
		(*data)->big_line = ft_strjoin((*data)->big_line, ptr);
		free(ptr);
		ptr = get_next_line(fd);
	}
	close(fd);
	(*data)->exit = 0;
	(*data)->player = 0;
	(*data)->collectible = 0;
	if (!characters_checking((*data)->big_line, data))
	{
		write(2, "Error\nmap contain invalid character.", 41);
		free((*data)->big_line);
		exit(EXIT_FAILURE);
	}
}

// void leaks(void)
// {
// 	system("leaks so_long");
// }

int	main(int ac, char **av)
{
	t_data	*data;

	// atexit(leaks);
	intializing_all_variables(&data);
	if (ac != 2 || !checking_arguments(av[1]))
		exit(1);
	data = malloc(sizeof(t_data));
	if (!data)
		exit(1);
	reading_map_file(av[1], &data);
	map_checking(&data);
	all_about_mlx(data);
	mlx_terminate(data->mlx);
}