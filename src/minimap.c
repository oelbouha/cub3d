/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:33:26 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/19 10:16:19 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_minimap(t_data *d)
{
	d->minimap.w = 200;
	d->minimap.h = 200;
	if (init_canvas(d, &d->minimap))
		return (1);
	return (0);
}

void	draw_rectangle(t_canvas *c, t_vect_i start, t_vect_i size, int color)
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

void	draw_line_minimap(t_data *d, t_vect s, t_vect e, int color)
{
	t_vect_i	start;
	t_vect_i	end;
	int			side;
	int			margin;
	int			yoff;

	margin = 0;
	side = (d->minimap.w - (d->house.w - 1) * margin) / d->house.w;
	if (d->house.w < d->house.h)
		side = (d->minimap.h - (d->house.h - 1) * margin) / d->house.h;
	yoff = d->minimap.h - (d->house.h * (side + margin) - margin);
	start.x = ((int)s.x) * (side + margin) + (s.x - (int)s.x) * side;
	start.y = ((int)s.y) * (side + margin) + (s.y - (int)s.y) * side;
	end.x = ((int)e.x) * (side + margin) + (e.x - (int)e.x) * side;
	end.y = ((int)e.y) * (side + margin) + (e.y - (int)e.y) * side;
	draw_line(&d->minimap, start, end, color);
}

void	draw_minimap(t_data *d)
{
	int	side;
	int	margin;
	int	x;
	int	y;
	int	yoff;

	margin = 0;
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
					(t_vect_i){.x = x * (side + margin), .y = yoff + y * (side + margin)}, 
					(t_vect_i){.x = side, .y = side}, 0x00ff0000);
			else
				draw_rectangle(&d->minimap,
					(t_vect_i){.x = x * (side + margin), .y = yoff + y * (side + margin)}, 
					(t_vect_i){.x = side, .y = side}, 0x00ffffff);
		}
	}
	draw_rectangle(&d->minimap, (t_vect_i){.x=d->cam.pos.x*side - 1, .y=d->cam.pos.y*side - 1}, (t_vect_i){.x=3, .y=3}, 0x00fcba03);
	mlx_put_image_to_window(d->mlx, d->win, d->minimap.img, 0, 0);
}
