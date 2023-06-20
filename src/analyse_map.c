/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:01:28 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/20 12:28:40 by ysalmi           ###   ########.fr       */
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
