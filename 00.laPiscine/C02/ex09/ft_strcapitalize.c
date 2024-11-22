/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 09:13:34 by dongmpar          #+#    #+#             */
/*   Updated: 2024/08/19 01:07:32 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len_str(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	len;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	len = ft_len_str(str);
	i = 1;
	while (i < len)
	{
		if (!((str[i - 1] >= 'A' && str[i - 1] <= 'Z') \
			|| (str[i - 1] >= 'a' && str[i - 1] <= 'z') \
				|| (str[i - 1] >= '0' && str[i - 1] <= '9')))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
		}
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
