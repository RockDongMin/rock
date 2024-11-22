/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:55:35 by dongmpar          #+#    #+#             */
/*   Updated: 2024/08/25 13:40:06 by dongmpar         ###   ########.fr       */
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
}

int	main(int argc, char *argv[])
{
	if (argc >= 1)
	{
		ft_putstr(argv[0]);
		write(1, "\n", 1);
	}
	return (0);
}
