/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:03:06 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/20 11:52:24 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_spaces(char *str)
{
	int i;

	i = -1;
	while (str[++i] && str[i] == ' ')
		;
	return (&str[i]);	
}

void	print(t_list *lst)
{
	while (lst)
	{
		printf("lst: ->:%s:\n", lst->content);
		lst = lst->next;
	}
}
void	print_arr(char **arr)
{
	if (arr == NULL)
		return ;
	for(int i = 0; arr[i]; i++)
		printf("arr[]: %s:\n",  arr[i]);
}
