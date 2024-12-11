#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

int	base_correctness(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base == NULL || ft_strlen(base) == 1)
		return (0);
	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		if (base[i] >= 9 && base[i] <= 13)
			return (0);
		while (base[i + j + 1])
		{
			if (base[i] == base[i + j + 1])
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}

int	ft_putnbr_base(long int nbr, char *base)
{
	long int	overflow_case;
	int			size;
	int			bytes_written;

	size = base_correctness(base);
	if (size == 0)
		return (0);
	bytes_written = 0;
	overflow_case = nbr;
	if (overflow_case < 0)
	{
		write(1, "-", 1);
		bytes_written++;
		overflow_case = -overflow_case;
	}
	if (overflow_case < size)
	{
		write(1, &base[overflow_case], 1);
		bytes_written++;
	}
	else
	{
		bytes_written += ft_putnbr_base(overflow_case / size, base);
		write(1, &base[overflow_case % size], 1);
		bytes_written++;
	}
	return (bytes_written);
}
