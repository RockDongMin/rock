/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:03:57 by dongmpar          #+#    #+#             */
/*   Updated: 2024/09/01 17:49:52 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(str);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*val;
	int			i;

	if (ac < 0 || av == NULL)
		return (NULL);
	val = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!val)
		return (NULL);
	i = 0;
	while (i < ac && av != NULL)
	{
		val[i].size = ft_strlen(av[i]);
		val[i].str = av[i];
		val[i].copy = ft_strdup(av[i]);
		if (val[i].str == NULL)
			return (NULL);
		if (val[i].copy == NULL)
			return (NULL);
		i++;
	}
	val[i].str = 0;
	val[i].size = 0;
	val[i].copy = 0;
	return (val);
}
