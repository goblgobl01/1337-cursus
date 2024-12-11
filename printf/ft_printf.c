# include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list arguments;
	int i;

	i = 0;
	va_start(arguments, format);
	while(format[i])
	{
		if(format[i] != '%')
		{
			ft_putchar(format[i++]);
			continue ;
		}
		else
		{
			if(format[++i] == 'c')
				ft_putchar(va_arg(arguments, int));
			else if(format[++i] == 's')
				ft_putstr(va_arg(arguments, char *));
			else if(format[++i] == 'p')
			{
				ft_putstr("0x");
				ft_putnbr_base(va_arg(arguments, int), "0123456789abcdef");
			}
			else if(format[++i] == 'd')
				ft_putnbr_base(va_arg(arguments, int), "0123456789");
			else if(format[++i] == 'i')
				ft_putnbr_base(va_arg(arguments, int), "0123456789");
			else if(format[++i] == 'u')
				ft_putnbr_base((unsigned int)va_arg(arguments, int), "0123456789");
			else if(format[++i] == 'x')
				ft_putnbr_base(va_arg(arguments, int), "0123456789abcdef");
			else if(format[++i] == 'X')
				ft_putnbr_base(va_arg(arguments, int), "0123456789ABCDEF");
			else if(format[++i] == '%')
				ft_putchar('%');
			i++;
		}
	}
	return (0);
}
