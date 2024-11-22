/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:15:41 by dongmpar          #+#    #+#             */
/*   Updated: 2024/08/19 11:25:20 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_dec_2_hex(char c)
{
	unsigned char	uc;
	char			s;
	char			a;
	char			b;

	uc = 0;
	uc = (unsigned char)c;
	s = '\\';
	a = 0;
	b = 0;
	ft_putchar(s);
	a = uc / 16;
	b = uc % 16;
	if (a <= 9)
		ft_putchar(a + '0');
	else
		ft_putchar(a - 10 + 'a');
	if (b <= 9)
		ft_putchar(b + '0');
	else
		ft_putchar(b - 10 + 'a');
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] != 127)
			ft_putchar(str[i]);
		else
			ft_dec_2_hex(str[i]);
		i++;
	}
}
