/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 08:07:18 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/19 13:12:16 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color_from_texture(t_canvas c, t_hit hit, float posx, int posy)
{
	int		color;
	int		x;
	int		y;
	float	r;

	r = (double)hit.line_height / c.h;
	x = posx * c.w;
	y = posy / r;

	color = get_pxl_color(&c, x, y);
	//printf("color: %d\n", color);
	return (color);
}

void	render_scene(t_data *d)
{
	int		x;
	int		y;
	double	px;
	t_vect	ray;
	t_hit	hit;

	t_canvas	c;
	c.img = mlx_xpm_file_to_image(d->mlx, "/Users/ysalmi/code/in_progress/cub3d/bg.xpm", &c.w, &c.h);
	c.addr = mlx_get_data_addr(c.img, &c.bpp, &c.line_len, &c.endian);
	

	x = -1;
	// draw floor and cieling
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
			if (y >= hit.draw_start && y < hit.draw_start + hit.line_height)
			{
				int	color;
				if (hit.side == LEFT)
					color = get_color_from_texture(c, hit, hit.wall_pos, y - hit.draw_start);
				else
					color = 100 << (hit.side << 8);
				paint_pxl(&d->view, x, y, color);
			}
			else if (y > HEIGHT / 2)//floor
				paint_pxl(&d->view, x, y, 0x008b4513);
			else // ceiling
				paint_pxl(&d->view, x, y, 0x005a5a5a);
		}
	}
	mlx_put_image_to_window(d->mlx, d->win, d->view.img, 0, 0);
}
