/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:14:16 by dongmpar          #+#    #+#             */
/*   Updated: 2024/10/25 15:16:00 by dongmpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	f_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*loop_lst;

	loop_lst = *lst;
	if (*lst)
	{
		while (loop_lst)
		{
			n_lst = loop_lst->next;
			f_lstdelone(loop_lst, del);
			loop_lst = n_lst;
		}
		*lst = NULL;
	}
}
