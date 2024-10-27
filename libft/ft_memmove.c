/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:24:12 by dongmpar          #+#    #+#             */
/*   Updated: 2024/10/25 15:24:17 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;

	d = dest;
	if (dest == src)
		return (dest);
	if (dest < src)
	{
		while (n-- > 0)
			*d++ = *(unsigned char *)src++;
	}
	else
	{
		while (n-- > 0)
			*(d + n) = *(unsigned char *)(src + n);
	}
	return (dest);
}
