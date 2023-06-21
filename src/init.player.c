/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:24:52 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/21 17:54:02 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_north(t_data *d)
{
	d->cam.dir = (t_vect){.x = 0, .y = -1};
	d->cam.plane = (t_vect){.x = 0.8, .y = 0};
	d->cam.sideway = (t_vect){.x = 1.0, .y = 0};
}

void	setup_south(t_data *d)
{
	d->cam.dir = (t_vect){.x = 0, .y = 1};
	d->cam.plane = (t_vect){.x = -0.8, .y = 0};
	d->cam.sideway = (t_vect){.x = -1.0, .y = 0};
}

void	setup_west(t_data *d)
{
	d->cam.dir = (t_vect){.x = -1, .y = 0};
	d->cam.plane = (t_vect){.x = 0, .y = -0.8};
	d->cam.sideway = (t_vect){.x = 0, .y = -1.0};
}

void	setup_east(t_data *d)
{
	d->cam.dir = (t_vect){.x = 1, .y = 0};
	d->cam.plane = (t_vect){.x = 0, .y = 0.8};
	d->cam.sideway = (t_vect){.x = 0, .y = 1.0};
}

void	init_player(t_data *d)
{
	int		i;
	int		j;

	i = -1;
	while (d->house.map[++i])
	{
		j = -1;
		while (d->house.map[i][++j])
		{
			if (ft_strchr("NSWE", d->house.map[i][j]))
			{
				d->cam.pos = (t_vect){.x = j + 0.5, .y = i + 0.5};
				if (d->house.map[i][j] == 'N')
					setup_north(d);
				else if (d->house.map[i][j] == 'S')
					setup_south(d);
				else if (d->house.map[i][j] == 'E')
					setup_east(d);
				else if (d->house.map[i][j] == 'W')
					setup_west(d);
				d->house.map[i][j] = '0';
			}
		}
	}	
}
