/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 09:25:30 by dongmpar          #+#    #+#             */
/*   Updated: 2024/08/17 16:35:24 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	cp;
	int	i;
	int	j;

	i = size;
	while (i > 0)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				cp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = cp;
			}
			j++;
		}
		i--;
	}
}
