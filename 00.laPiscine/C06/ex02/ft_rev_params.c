/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:56:48 by dongmpar          #+#    #+#             */
/*   Updated: 2024/08/25 14:53:10 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *argv)
{
	int	len;

	len = 0;
	while (argv[len])
		len++;
	write(1, argv, len);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (argc >= 1)
	{
		i = i - 1;
		while (i > 0)
		{
			ft_putstr(argv[i]);
			i--;
		}
	}
	return (0);
}
