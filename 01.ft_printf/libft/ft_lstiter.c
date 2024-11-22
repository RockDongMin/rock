/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:17:06 by dongmpar          #+#    #+#             */
/*   Updated: 2024/10/25 15:17:09 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*n_lst;

	n_lst = lst;
	while (n_lst)
	{
		(*f)(n_lst->content);
		n_lst = n_lst->next;
	}
}
