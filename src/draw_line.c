/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_ed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:06:02 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/19 15:48:40 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_canvas *c, t_vect_i s, t_vect_i e, int color)
{
	t_vect_i	dlt;
	t_vect_i	step;
	int			err;
	int			e2;

	dlt.x = abs(e.x - s.x);
	dlt.y = abs(e.y - s.y);
	step.x = 2 * (s.x < e.x) - 1;
	step.y = 2 * (s.y < e.y) - 1;
	err = (dlt.x > dlt.y) * dlt.x / 2 - (dlt.x <= dlt.y) * dlt.y / 2;
	while (s.x != e.x || s.y != e.y)
	{
		paint_pxl(c, s.x, s.y, color);
		e2 = err;
		if (e2 > -dlt.x)
		{
			err -= dlt.y;
			s.x += step.x;
		}
		if (e2 < dlt.y)
		{
			err += dlt.x;
			s.y += step.y;
		}
	}
}
