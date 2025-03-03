#include "header.h"

int checking_arguments(char *str)
{
	int		length;
	char	*string;
	int		i;

	length = ft_strlen(str);
	string = "reb";
	length--;
	i = 0;
	while(i < 3)
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
	return (1);
}
int	is_valid_character(char c, t_data **all_data)
{
	char	*str;
	int		i;

	i = 0;
	str = "01CEP";
	while(str[i])
	{
		if(str[i] == 'C')
			(*all_data)->collectible++;
		if(str[i] == 'E')
			(*all_data)->exit++;
		if(str[i] == 'P')
			(*all_data)->player++;
		if(str[i] == c)
			return (1);
		i++;
	}
	return(0);
}

int	map_checking(char *str, t_data **all_data)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(!is_valid_character(str[i], all_data))
			return(0);
		i++;
	}
	return(1);
}

char *reading_map_file(char *str, t_data **all_data)
{
	char	*ptr;
	char	*big_line;
	int		fd;
	int		count;

	fd = open(str, O_RDONLY);
	ptr = get_next_line(fd);
	big_line = NULL;
	while(ptr)
	{
		big_line = ft_strjoin(big_line, ptr);
		free(ptr);
		ptr = get_next_line(fd);
	}
	if(!map_checking(big_line, all_data))
		free(big_line);
	close(fd);
	return (big_line);
}

int main(int ac, char **av)
{
	t_data	*all_data;

	if (ac != 2 || !checking_arguments(av[1]))
		exit(0);
	all_data = malloc(sizeof(t_data));
	if(!all_data)
		exit(0);
	reading_map_file(av[1], &all_data);
}