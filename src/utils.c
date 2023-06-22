/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:03:06 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/22 13:24:24 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	arr_len(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		;
	return (i);
}

char	*skip_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] == ' ')
		;
	return (&str[i]);
}

int	check_extension(char *map_path)
{
	char	*ptr;

	ptr = ft_strchr(map_path, '.');
	if (ptr == NULL || ft_strcmp(ptr, ".cub"))
		return (1);
	return (0);
}

int	map_is_empty(t_list *lst)
{
	t_list	*cur;
	int		i;
	char	*str;

	cur = lst;
	while (cur)
	{
		i = -1;
		str = cur->content;
		while (str[++i])
		{
			if (ft_strchr("01NSWE", str[i]))
				return (0);
		}
		cur = cur->next;
	}
	return (1);
}
