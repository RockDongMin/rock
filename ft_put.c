/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rockdongmin <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:21:15 by rockdongmin       #+#    #+#             */
/*   Updated: 2024/11/19 22:35:46 by rockdongmin      ###   ########.fr       */
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
	{
		write(1, "(null)", 6);
		return (6);
	}
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

	addr = (unsigned long)ptr;
	hex = "0123456789abcdef";
	if (addr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i = 15;
	while (i >= 0)
	{
		buffer[i--] = hex[addr % 16];
		addr = addr / 16;
	}
	write(1, "0x", 2);
	i = 0;
	while (i < 16)
		write(1, &buffer[i++], 1);
	return (18);
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
