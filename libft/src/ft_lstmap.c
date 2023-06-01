/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:44:27 by ysalmi            #+#    #+#             */
/*   Updated: 2022/10/02 14:34:03 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cursor;
	t_list	*first;

	if (!lst)
		return (0);
	first = malloc(sizeof(t_list));
	if (!first)
		return (0);
	first->content = f(lst->content);
	cursor = first;
	lst = lst->next;
	while (lst)
	{
		cursor->next = ft_lstnew(f(lst->content));
		cursor = cursor->next;
		if (!cursor)
		{
			ft_lstclear(&first, del);
			return (0);
		}
		lst = lst->next;
	}
	return (first);
}
