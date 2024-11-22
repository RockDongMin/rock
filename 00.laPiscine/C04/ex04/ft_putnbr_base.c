/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:56:14 by dongmpar          #+#    #+#             */
/*   Updated: 2024/08/24 15:20:22 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_base_check(char *base)
{
	int	l;
	int	i;
	int	j;

	l = 0;
	while (base[l])
		l++;
	if (l < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' \
				|| (base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (l);
}

void	ft_putnbr(int nbr, char *base, int b_num)
{
	long long	nb;

	nb = nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= b_num)
	{
		ft_putnbr(nb / b_num, base, b_num);
		ft_putnbr(nb % b_num, base, b_num);
	}
	else
		write(1, &base[nb], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	b_num;

	b_num = ft_base_check(base);
	if (b_num < 2)
		return ;
	ft_putnbr(nbr, base, b_num);
	return ;
}
