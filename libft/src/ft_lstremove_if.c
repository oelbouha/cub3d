/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:02:43 by ysalmi            #+#    #+#             */
/*   Updated: 2023/04/15 13:04:14 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove_if(t_list **lst, t_lstcmp need_rm, t_lstdel del)
{
	t_list	*cur;
	t_list	*prev;

	if (lst == NULL || *lst == NULL || need_rm == NULL || del == NULL)
		return ;
	cur = *lst;
	prev = NULL;
	while (cur)
	{
		if (need_rm(cur->content))
		{
			if (prev == NULL)
				*lst = cur->next;
			else
				prev->next = cur->next;
			ft_lstdelone(cur, del);
		}
		prev = cur;
		cur = cur->next;
	}
}
