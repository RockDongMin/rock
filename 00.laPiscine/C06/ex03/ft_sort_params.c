/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:55:05 by dongmpar          #+#    #+#             */
/*   Updated: 2024/08/25 21:28:38 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_by_ascii(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < argc - 1)
	{
		j = 1;
		while (j < argc - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				temp = argv[j + 1];
				argv[j + 1] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
}

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
		ft_sort_by_ascii(argc, argv);
		i = 1;
		while (argv[i])
		{
			ft_putstr(argv[i]);
			i++;
		}
	}
	return (0);
}
