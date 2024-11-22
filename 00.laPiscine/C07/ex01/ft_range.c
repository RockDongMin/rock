/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:39:46 by dongmpar          #+#    #+#             */
/*   Updated: 2024/08/27 18:39:07 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*val;
	int	dif;
	int	i;

	if (min >= max)
		return (0);
	dif = max - min;
	val = (int *)malloc(dif * sizeof(int));
	if (!(val))
		return (0);
	i = 0;
	while (min + i < max)
	{
		val[i] = min + i;
		i++;
	}
	return (val);
}
