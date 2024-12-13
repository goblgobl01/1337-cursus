/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:28:02 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/12/13 10:34:41 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_printf(const char *format, ...);
int		fun(unsigned long nbr, char *base);
int		ft_putstr(char *str);
int		fun1(long int nb);

#endif