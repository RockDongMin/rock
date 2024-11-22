/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:39:18 by dongmpar          #+#    #+#             */
/*   Updated: 2024/08/20 15:27:21 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_like(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		if (ft_like(&str[i], to_find))
			return (&str[i]);
		i++;
	}
	return (0);
}
