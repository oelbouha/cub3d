/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:57:29 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/20 11:50:29 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cant_be_in_map(char *str)
{
	if (ft_issubset(" ", str) || ft_strchr(str, '0') || ft_strchr(str, '1')
		|| ft_strchr(str, ' '))
		return (0);
	return (1);
}

int	analyze_map(t_list *lst)
{
	t_list *cur;

	cur = lst;
	while (cur)
	{
		if (cant_be_in_map(cur->content))
			return (print_error_msg("invalid map"), 1);
		cur = cur->next;
	}
	return (0);
}
