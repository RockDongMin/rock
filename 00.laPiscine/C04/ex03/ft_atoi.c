/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:40:11 by dongmpar          #+#    #+#             */
/*   Updated: 2024/08/23 11:05:56 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_space(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	ft_mark(char *str, int *i)
{
	int	n;

	n = 0;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			n++;
		(*i)++;
	}
	return (n % 2);
}

int	ft_atoi(char *str)
{
	int		i;
	int		n;
	int		out;

	i = ft_space(str);
	n = ft_mark(str, &i);
	out = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + (str[i] - '0');
		i++;
	}
	if (n)
		out = -out;
	return (out);
}
