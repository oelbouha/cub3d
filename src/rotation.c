/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:52:13 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/18 13:45:57 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	keydown_handler(int	key, t_data *d)
{
	static t_vect	rot;
	t_camera		*cam;
	int				dir;

	dir = 0;
	if (key == K_LEFT)
		dir = -1;
	else if (key == K_RIGHT)
		dir = 1;
	else if (key == K_W)
		d->cam.pos.y -= 0.05;
	else if (key == K_S)
		d->cam.pos.y += 0.05;
	else if (key == K_A)
		d->cam.pos.x -= 0.05;
	else if (key == K_D)
		d->cam.pos.x += 0.05;
	else if (key == K_ESC)
		return (destroy(d), exit(0), 1);
	else
		return (printf("key:%d\n", key), 0);

	if (rot.x == 0 && rot.y == 0)
		rot = (t_vect){.x = cos(M_PI / 90.0), .y = sin(M_PI / 90.0)};
	if (dir)
	{
		cam = &d->cam;
		cam->dir.x = cam->dir.x * rot.x - cam->dir.y * dir * rot.y;
		cam->dir.y = cam->dir.x * dir * rot.y + cam->dir.y * rot.x;
		cam->plane.x = cam->plane.x * rot.x - cam->plane.y * dir * rot.y;
		cam->plane.y = cam->plane.x * dir * rot.y + cam->plane.y * rot.x;
	}
	draw_minimap(d);
	render_scene(d);
	mlx_put_image_to_window(d->mlx, d->win, d->minimap.img, 0, 0);
	return (0);
}
