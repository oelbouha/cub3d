/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:03:06 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/21 10:38:46 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] == ' ')
		;
	return (&str[i]);
}

void	print_arr(char **arr)
{
	if (!arr)
		return ;
	for(int i = 0; arr[i]; i++)
		printf("arr :%s:\n", arr[i]);
}