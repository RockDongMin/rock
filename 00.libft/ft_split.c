/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:29:42 by dongmpar          #+#    #+#             */
/*   Updated: 2024/10/25 15:29:53 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsize(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			size++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (i > 0 && s[i - 1] != c)
		size++;
	return (size);
}

static char	*ft_splitdup(char const *s, char c)
{
	char	*dest;
	int		i;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**mem_free(char **dest, int j)
{
	while (--j >= 0)
		free(dest[j]);
	free(dest);
	return (NULL);
}

static char	**get_split(char const *s, char c, int size)
{
	char	**dest;
	int		i;
	int		j;

	dest = (char **)malloc(sizeof(char *) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < size)
	{
		if (s[i] != c)
		{
			dest[j] = ft_splitdup(&s[i], c);
			if (!dest[j])
				return (mem_free(dest, j));
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	dest[j] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		size;

	if (!s)
		return (NULL);
	size = getsize(s, c);
	return (get_split(s, c, size));
}
