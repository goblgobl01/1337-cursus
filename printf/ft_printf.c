# include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list arguments;
	int i;

	va_start(arguments, format);
	while(format[i])
	{
		if(format[i] != '%')
		{
			ft_putchar(format[i++]);
			continue ;
		}
	}
	return (0);
}