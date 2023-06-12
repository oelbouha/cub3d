/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:33:26 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/10 16:29:19 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_minimap(t_data *d)
{
	d->minimap.w = 600;
	d->minimap.h = 600;
	if (init_canvas(d, &d->minimap))
		return (1);
	return (0);
}

void	draw_rectangle(t_canvas *c, t_vect start, t_vect size, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < size.y)
	{
		x = -1;
		while (++x < size.x)
		{
			paint_pxl(c, start.x + x, start.y + y, color);
		}
	}
}

void	draw_minimap(t_data *d)
{
	int	side;
	int	margin;
	int	x;
	int	y;
	int	yoff;

	margin = 2;
	side = (d->minimap.w - (d->house.w - 1) * margin) / d->house.w;
	if (d->house.w < d->house.h)
		side = (d->minimap.h - (d->house.h - 1) * margin) / d->house.h;
	yoff = d->minimap.h - (d->house.h * (side + margin) - margin);
	paint_canvas(&d->minimap, 0xffffffff);
	y = -1;
	while (++y < d->house.h)
	{
		x = -1;
		while (++x < d->house.w)
		{
			if (d->house.map[y][x] == '1')
				draw_rectangle(&d->minimap,
					(t_vect){.x = x * (side + margin), .y = yoff + y * (side + margin)}, 
					(t_vect){.x = side, .y = side}, 0x00ff0000);
			else
				draw_rectangle(&d->minimap,
					(t_vect){.x = x * (side + margin), .y = yoff + y * (side + margin)}, 
					(t_vect){.x = side, .y = side}, 0xffffffff);
		}
	}
	mlx_put_image_to_window(d->mlx, d->win, d->minimap.img, 10, 10);
}
