/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:18:51 by dongmpar          #+#    #+#             */
/*   Updated: 2024/10/25 15:18:56 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*n_lst;

	if (!lst)
		return (NULL);
	n_lst = lst;
	while (n_lst->next)
		n_lst = n_lst->next;
	return (n_lst);
}
