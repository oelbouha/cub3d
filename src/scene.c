/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 08:07:18 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/21 19:12:11 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color_from_texture(t_canvas c, t_hit hit, int posy)
{
	int		color;
	int		x;
	int		y;
	float	r;
	float	posx;

	r = (double)hit.line_height / c.h;
	posx = hit.wall_pos;
	x = posx * c.w;
	y = posy / r;
	color = get_pxl_color(&c, x, y);
	return (color);
}

int	get_color(t_data *d, t_hit hit, int screen_y)
{
	t_canvas	c;
	int			posy;

	if (hit.side == BOTTOM)
		c = d->house.north;
	else if (hit.side == TOP)
		c = d->house.south;
	else if (hit.side == LEFT)
		c = d->house.east;
	else
		c = d->house.west;
	posy = screen_y - hit.draw_start;
	return (get_color_from_texture(c, hit, posy));
}

void	render_scene(t_data *d)
{
	t_vect_i	w;
	t_vect		ray;
	t_hit		hit;
	double		px;

	w.x = -1;
	while (++w.x < WIDTH)
	{
		px = 2.0 * w.x / (double) WIDTH - 1;
		ray = (t_vect){.x = d->cam.dir.x + px * d->cam.plane.x,
			.y = d->cam.dir.y + px * d->cam.plane.y};
		hit = raycaster(d, d->cam.pos, ray);
		draw_line_minimap(d, d->cam.pos, hit.dist, 0x00f0f000);
		w.y = -1;
		while (++w.y < HEIGHT)
		{
			if (w.y >= hit.draw_start && w.y < hit.draw_end)
				paint_pxl(&d->view, w.x, w.y, get_color(d, hit, w.y));
			else if (w.y > HEIGHT / 2)
				paint_pxl(&d->view, w.x, w.y, d->house.floor);
			else
				paint_pxl(&d->view, w.x, w.y, d->house.ceiling);
		}
	}
	mlx_put_image_to_window(d->mlx, d->win, d->view.img, 0, 0);
}
