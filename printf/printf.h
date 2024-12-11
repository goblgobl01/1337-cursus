# ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdlib.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

void	ft_putchar(char c);
int		ft_printf(const char *format, ...);
void	ft_putnbr_base(long int nbr, char *base);
void	ft_putstr(char *str);

# endif