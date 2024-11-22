/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:36:23 by dongmpar          #+#    #+#             */
/*   Updated: 2024/10/25 15:41:12 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int	ft_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1);
	while (i > 0)
	{
		if (ft_strchr(set, s1[i - 1]) == 0)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1)
		return (0);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * end - start + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, &s1[start], end - start + 1);
	return (str);
}
