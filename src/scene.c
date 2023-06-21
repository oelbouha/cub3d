/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 08:07:18 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/21 11:17:08 by ysalmi           ###   ########.fr       */
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

int	get_color(t_data *d, t_hit hit, int posy)
{
	t_canvas	c;

	if (hit.side == BOTTOM)
		c = d->house.north;
	else if (hit.side == TOP)
		c = d->house.south;
	else if (hit.side == LEFT)
		c = d->house.east;
	else
		c = d->house.west;
	return (get_color_from_texture(c, hit, posy));
}

void	render_scene(t_data *d)
{
	int		x;
	int		y;
	double	px;
	t_vect	ray;
	t_hit	hit;

	x = -1;
	while (++x < WIDTH)
	{
		px = 2.0 * x / (double) WIDTH - 1;
		ray = (t_vect){.x = d->cam.dir.x + px * d->cam.plane.x,
			.y = d->cam.dir.y + px * d->cam.plane.y};
		hit = raycaster(d, d->cam.pos, ray);
		draw_line_minimap(d, d->cam.pos, hit.dist, 0x00f0f000);
		y = -1;
		while (++y < HEIGHT)
		{
			if (y >= hit.draw_start && y < hit.draw_end)
				paint_pxl(&d->view, x, y, get_color(d, hit, y - hit.draw_start));
			else if (y > HEIGHT / 2)//floor
				paint_pxl(&d->view, x, y, d->house.floor);
			else // ceiling
				paint_pxl(&d->view, x, y, d->house.ceiling);
		}
	}
	mlx_put_image_to_window(d->mlx, d->win, d->view.img, 0, 0);
}
