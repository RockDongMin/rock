/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rockdongmin <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:21:15 by rockdongmin       #+#    #+#             */
/*   Updated: 2024/11/22 19:21:34 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	if (str == NULL)
		return (ft_putstr("(null)"));
	count = 0;
	while (str[count])
	{
		ft_putchar(str[count]);
		count++;
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long		addr;
	char				*hex;
	char				buffer[16];
	int					i;
	int					count;

	addr = (unsigned long)ptr;
	hex = "0123456789abcdef";
	if (addr == 0)
		return (ft_putstr("(nil)"));
	i = 15;
	while (addr != 0)
	{
		buffer[i--] = hex[addr % 16];
		addr = addr / 16;
	}
	write(1, "0x", 2);
	count = 2;
	i++;
	while (i < 16)
	{
		write(1, &buffer[i++], 1);
		count++;
	}
	return (count);
}

int	ft_puthex(unsigned int nb, int flag)
{
	char	*hex;
	int		count;

	if (flag)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
		count = count + ft_puthex(nb / 16, flag);
	count = count + ft_putchar(hex[nb % 16]);
	return (count);
}

int	ft_putnbr(long long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	if (nb < 0)
	{
		count = count + ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count = count + ft_putnbr(nb / 10);
	count = count + ft_putchar(nb % 10 + '0');
	return (count);
}
