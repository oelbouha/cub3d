/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:35:26 by ysalmi            #+#    #+#             */
/*   Updated: 2022/10/03 09:51:44 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cursor;
	t_list	*holder;

	if (lst && del)
	{
		cursor = *lst;
		while (cursor)
		{
			holder = cursor->next;
			ft_lstdelone(cursor, del);
			cursor = holder;
		}
		*lst = 0;
	}
}	
