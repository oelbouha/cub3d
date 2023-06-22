/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:57:29 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/22 13:28:20 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_enclosed(t_house *h)
{
	int	i;
	int	j;

	j = -1;
	while (h->map && h->map[++j])
	{
		i = -1;
		while (h->map[j][++i])
		{
			if (h->map[j][i] == '0')
			{
				if (i == 0 || i == h->w -1 || j == 0 || j == h->h - 1)
					return (0);
				else if (i != 0 && h->map[j][i - 1] == ' ')
					return (0);
				else if (i != h->w - 1 && h->map[j][i + 1] == ' ')
					return (0);
				else if (j != 0 && h->map[j - 1][i] == ' ')
					return (0);
				else if (j != h->h - 1 && h->map[j + 1][i] == ' ')
					return (0);
			}
		}
	}
	return (h->map != NULL);
}

int	cant_be_in_map(t_list *lst)
{
	t_list	*cur;
	char	*str;

	cur = lst;
	while (cur)
	{
		str = cur->content;
		if (ft_issubset(" ", str) || ft_strchr(str, '0') || ft_strchr(str, '1')
			|| ft_strchr(str, ' '))
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	check_map_characters(char **map)
{
	int		i;
	int		j;
	int		check;

	i = -1;
	check = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr(" 01NSWE", map[i][j]) || ft_issubset(" ", map[i]))
				return (1);
			if (ft_strchr("NSWE", map[i][j]))
			{
				if (check)
					return (1);
				check = 1;
			}
		}
	}
	if (check == 0)
		return (1);
	return (0);
}

char	**analyze_map(t_list *lst, t_house *h)
{
	char	**map;

	if (lst == NULL)
		return (print_error_msg("empty file"), NULL);
	else if (check_textures(h))
		return (print_error_msg("there is no textures in the map"), NULL);
	else if (h->ceiling == -1 || h->floor == -1)
		return (print_error_msg("there is no color in the map"), NULL);
	else if (cant_be_in_map(lst))
		return (print_error_msg("invalid map content"), NULL);
	map = get_rectangle_map(lst);
	if (map == NULL)
		return (NULL);
	if (check_map_characters(map))
		return (print_error_msg("invalid map characters"), free_arr(map), NULL);
	h->w = ft_strlen(map[0]);
	h->h = 0;
	while (map[h->h])
		h->h++;
	return (map);
}
