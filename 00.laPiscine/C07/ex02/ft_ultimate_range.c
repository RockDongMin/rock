/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:33:05 by dongmpar          #+#    #+#             */
/*   Updated: 2024/08/27 23:11:52 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*val;
	int	dif;
	int	i;

	dif = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	val = (int *)malloc(dif * sizeof(int));
	if (!(val))
		return (-1);
	i = 0;
	while (min + i < max)
	{
		val[i] = min + i;
		i++;
	}
	*range = val;
	return (dif);
}
