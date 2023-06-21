/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:33:26 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/21 19:17:59 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	t_vect_i	w;
	int			side;

	side = d->minimap.w / d->house.w;
	if (d->house.w < d->house.h)
		side = d->minimap.h / d->house.h;
	paint_canvas(&d->minimap, 0xffffffff);
	w.y = -1;
	while (++w.y < d->house.h)
	{
		w.x = -1;
		while (++w.x < d->house.w)
		{
			if (d->house.map[w.y][w.x] == '1')
				draw_rectangle(&d->minimap,
					(t_vect_i){.x = w.x * side, .y = w.y * side},
					(t_vect_i){.x = side, .y = side}, 0x00ff0000);
			else if (d->house.map[w.y][w.x] == '0')
				draw_rectangle(&d->minimap,
					(t_vect_i){.x = w.x * side, .y = w.y * side},
					(t_vect_i){.x = side, .y = side}, 0x00ffffff);
		}
	}
	draw_rectangle(&d->minimap, (t_vect_i){.x = d->cam.pos.x * side - 2,
		.y = d->cam.pos.y * side - 2}, (t_vect_i){.x = 5, .y = 5}, 0x000000ff);
}
