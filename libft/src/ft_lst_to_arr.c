/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:40:23 by ysalmi            #+#    #+#             */
/*   Updated: 2023/05/13 18:23:39 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lst_to_arr(t_list *lst)
{
	char	**arr;
	int		size;
	int		i;

	size = ft_lstsize(lst);
	arr = ft_calloc(size + 1, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		arr[i] = lst->content;
		lst = lst->next;
	}
	return (arr);
}
