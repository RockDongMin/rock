/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:35:24 by dongmpar          #+#    #+#             */
/*   Updated: 2024/10/25 15:35:34 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_len;

	if (*little == 0 || !little)
		return ((char *)big);
	i = 0;
	l_len = ft_strlen(little);
	if (len < l_len)
		return (0);
	while (i <= len - l_len && big[i])
	{
		if (ft_memcmp(&big[i], little, l_len) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
