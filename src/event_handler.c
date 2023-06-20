/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:52:13 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/20 21:40:34 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_camera *cam, int dir)
{
	static t_vect	rot;

	if (rot.x == 0 && rot.y == 0)
		rot = (t_vect){.x = cos(M_PI / 80.0), .y = sin(M_PI / 80.0)};
	cam->dir.x = cam->dir.x * rot.x - cam->dir.y * dir * rot.y;
	cam->dir.y = cam->dir.x * dir * rot.y + cam->dir.y * rot.x;
	cam->plane.x = cam->plane.x * rot.x - cam->plane.y * dir * rot.y;
	cam->plane.y = cam->plane.x * dir * rot.y + cam->plane.y * rot.x;
	cam->sideway.x = cam->sideway.x * rot.x - cam->sideway.y * dir * rot.y;
	cam->sideway.y = cam->sideway.x * dir * rot.y + cam->sideway.y * rot.x;
}

void	move(t_camera *cam, int to, int dir, char **map)
{
	t_vect	m;
	t_vect	c;
	float	k;

	k = 0.08;
		//m = (t_vect){.x = dir * k * cam->dir.x, .y = dir * k * cam->dir.x}
	if (to == FORWARD)
	{
		m.x = dir * k * cam->dir.x;
		m.y = dir * k * cam->dir.y;
	}
	else
	{
		m.x = dir * k * cam->sideway.x;
		m.y = dir * k * cam->sideway.y;
	}
	k = 0.04;
	c = (t_vect){.x = cam->pos.x + m.x, .y = cam->pos.y + m.y};
	if (map[(int)(c.y + k)][(int)(c.x + k)] == '1')
		return ;
	if (map[(int)(c.y - k)][(int)(c.x - k)] == '1')
		return ;

	cam->pos.x += m.x;
	cam->pos.y += m.y;
}

int	keydown_handler(int key, t_data *d)
{
	int				dir;

	dir = 0;
	if (key == K_LEFT)
		rotate(&d->cam, -1);
	else if (key == K_RIGHT)
		rotate(&d->cam, 1);
	else if (key == K_W)
		move(&d->cam, FORWARD, 1, d->house.map);
	else if (key == K_S)
		move(&d->cam, FORWARD, -1, d->house.map);
	else if (key == K_A)
		move(&d->cam, SIDEWAY, -1, d->house.map);
	else if (key == K_D)
		move(&d->cam, SIDEWAY, 1, d->house.map);
	else if (key == K_ESC)
		return (destroy(d), exit(0), 1);
	else
		return (0);
	//draw_minimap(d);
	render_scene(d);
	//mlx_put_image_to_window(d->mlx, d->win, d->minimap.img, 0, 0);
	return (0);
}
