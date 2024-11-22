/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:42:09 by dongmpar          #+#    #+#             */
/*   Updated: 2024/08/25 13:57:45 by dongmpar         ###   ########.fr       */
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

	if (argc >= 1)
	{
		i = 1;
		while (argv[i])
		{
			ft_putstr(argv[i]);
			i++;
		}
	}
	return (0);
}
