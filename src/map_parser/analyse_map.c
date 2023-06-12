/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:01:28 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/05 11:56:33 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
 
 /*
 *
 * 
 * 
 * Objectives
 *  - check if map is enclosed
 *  - get player position
 */

int is_map_enclosed(char **map)
{
	int ret;
	int	h;
	int	w;
	int i;
	int j;

	ret = 0;
	if (map == NULL)
		return (ret);
	h = 0;
	while (map[h])
		h++;
	j = -1;
	while (map[++j])
	{
		i = -1;
		w = ft_strlen(map[j]);
		while (map[j][++i])
		{
			if (ft_strchr("NSWE", map[j][i]))
				ret = j + 1;
			if (!ft_strchr("1 ", map[j][i]))
			{
				if (i == 0 || j == 0)
					return (0);
				else if (i == w - 1 || j == h - 1)
					return (0);
				else if (i != 0 && map[j][i - 1] == ' ')
					return (0);
				else if (i != w - 1 && map[j][i + 1] == ' ')
					return (0);
				else if (j != 0 && map[j - 1][i] == ' ')
					return (0);
				else if (j != h - 1 && map[j + 1][i] == ' ')
					return (0);
			}
		}
	}
	return (ret);
}
