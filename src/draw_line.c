/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:06:02 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/13 13:04:16 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_canvas *c, t_vect_i s, t_vect_i e, int color)
{
	t_vect		slop;
	t_vect_i	step;
	int			done;

	step = (t_vect_i){.x = 1 - 2 * ( s.x > e.x ), .y = 1 - 2 * (s.y > e.y)};
	if (e.x == s.x)
	{
		while (s.y != e.y)
		{
			paint_pxl(c, s.x, s.y, color);
			s.y += step.y;
		}
		return ;
	}
	slop.x = 1.0 * (e.y - s.y) / (e.x - s.x);
	slop.y = e.y - 1.0 * slop.x * e.x;
	done = 0;
	while (!done)
	{
		int	y = slop.x * s.x + slop.y;
		while (y == s.y && !done)
		{
			paint_pxl(c, s.x, s.y, color);
			s.x += step.x;
			if (s.x == e.x && s.y == e.y)
				done = 1;
			y = slop.x * s.x + slop.y;
		}
		s.y += step.y;
		paint_pxl(c, s.x, s.y, color);
		if (s.x == e.x && s.y == e.y)
			done = 1;
	}
}
