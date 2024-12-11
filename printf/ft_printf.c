# include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list arguments;
	int i;
	int return_value;

	i = 0;
	return_value = 0;
	va_start(arguments, format);
	if(!format || !(*format))
		return (return_value);
	while(format[i])
	{
		if(format[i] != '%')
		{
			ft_putchar(format[i++]);
			return_value++;
			continue ;
		}
		else
		{
			if(format[i + 1] == 'c')
				return_value = return_value + ft_putchar((char)va_arg(arguments, int));
			else if(format[i + 1] == 's')
				return_value = return_value + ft_putstr(va_arg(arguments, char *));
			else if(format[i + 1] == 'p')
			{
				return_value = return_value + ft_putstr("0x");
				return_value = return_value + ft_putnbr_base(va_arg(arguments, int), "0123456789abcdef");
			}
			else if(format[i + 1] == 'd')
				return_value = return_value + ft_putnbr_base(va_arg(arguments, int), "0123456789");
			else if(format[i + 1] == 'i')
				return_value = return_value + ft_putnbr_base(va_arg(arguments, int), "0123456789");
			else if(format[i + 1] == 'u')
				return_value = return_value + ft_putnbr_base((unsigned int)va_arg(arguments, int), "0123456789");
			else if(format[i + 1] == 'x')
				return_value = ft_putnbr_base(va_arg(arguments, int), "0123456789abcdef");
			else if(format[i + 1] == 'X')
				return_value = ft_putnbr_base(va_arg(arguments, int), "0123456789ABCDEF");
			else if(format[i + 1] == '%')
				return_value = return_value + ft_putchar('%');
			i += 2;
		}
	}
	return (return_value);
}
