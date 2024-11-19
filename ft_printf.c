/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rockdongmin <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:09:06 by rockdongmin       #+#    #+#             */
/*   Updated: 2024/11/19 22:24:04 by rockdongmin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_specifier(const char fs, va_list *args)
{
	if (fs == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (fs == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (fs == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (fs == 'd' || fs == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (fs == 'u')
		return (ft_putnbr(va_arg(*args, unsigned int)));
	else if (fs == 'x' || fs == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), fs == 'X'));
	else if (fs == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			printed_char;
	int			i;

	va_start(args, format);
	printed_char = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed_char = printed_char + ft_format_specifier(format[i], &args);
		}
		else
			printed_char = printed_char + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (printed_char);
}
