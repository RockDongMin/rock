/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:30:29 by dongmpar          #+#    #+#             */
/*   Updated: 2024/08/29 19:41:35 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_length(int size, char **strs, char *sep)
{
	int	len_str;
	int	len_sep;
	int	i;
	int	j;

	len_str = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			len_str++;
			j++;
		}
		i++;
	}
	len_sep = 0;
	while (sep[len_sep])
		len_sep++;
	return (len_str + len_sep * (size - 1));
}

void	ft_while(int size, char **strs, char *sep, char *val)
{
	int		i;
	int		j;
	int		k;
	int		p;

	p = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			val[p++] = strs[i][j++];
		if (i < size - 1)
		{
			k = 0;
			while (sep[k])
				val[p++] = sep[k++];
		}
		i++;
	}
	val[p] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*val;
	int		len_tot;

	if (size <= 0)
	{
		val = (char *)malloc(1 * sizeof(char));
		val[0] = '\0';
		return (val);
	}
	len_tot = ft_length(size, strs, sep);
	val = (char *)malloc((len_tot + 1) * sizeof(char));
	if (!val)
		return (NULL);
	ft_while(size, strs, sep, val);
	return (val);
}
