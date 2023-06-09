/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:03:06 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/08 16:08:04 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print(t_list *lst)
{
	while (lst)
	{
		printf("lst: %s\n", lst->content);
		lst = lst->next;
	}
}
void	print_arr(char **arr)
{
	for(int i = 0; arr[i]; i++)
		printf("arr[]: %s:\n",  arr[i]);
}