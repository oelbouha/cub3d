/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.rectangle.map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:12:08 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/22 13:25:44 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_maxlength(t_list *lst)
{
	int		len;
	t_list	*cur;
	int		max_length;

	cur = lst;
	max_length = 0;
	while (cur)
	{
		len = ft_strlen(cur->content);
		if (len > max_length)
			max_length = len;
		cur = cur->next;
	}
	return (max_length);
}

char	**convert_lst_to_arr(t_list *lst, int max_len)
{
	char	**arr;
	t_list	*cur;
	int		i;

	arr = malloc((ft_lstsize(lst) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	cur = lst;
	while (cur)
	{
		arr[i] = ft_calloc(max_len + 1, sizeof(char));
		if (arr[i] == NULL)
			return (free(arr), NULL);
		ft_memset(arr[i], ' ', max_len);
		arr[i] = ft_memmove(arr[i], cur->content, ft_strlen(cur->content));
		cur = cur->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**get_rectangle_map(t_list *lst)
{
	t_list	*cur;
	int		max_len;
	char	**arr;

	if (lst == NULL)
		return (NULL);
	arr = NULL;
	cur = lst;
	while (cur && ft_issubset(" ", cur->content))
		cur = cur->next;
	if (cur == NULL)
		return (print_error_msg("there is no map content"), NULL);
	max_len = get_maxlength(cur);
	arr = convert_lst_to_arr(cur, max_len);
	return (arr);
}
