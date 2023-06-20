/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:52:13 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/20 13:01:46 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_camera *cam, int dir)
{
	static t_vect	rot;

	if (rot.x == 0 && rot.y == 0)
		rot = (t_vect){.x = cos(M_PI / 90.0), .y = sin(M_PI / 90.0)};
	cam->dir.x = cam->dir.x * rot.x - cam->dir.y * dir * rot.y;
	cam->dir.y = cam->dir.x * dir * rot.y + cam->dir.y * rot.x;
	cam->plane.x = cam->plane.x * rot.x - cam->plane.y * dir * rot.y;
	cam->plane.y = cam->plane.x * dir * rot.y + cam->plane.y * rot.x;
	cam->sideway.x = cam->sideway.x * rot.x - cam->sideway.y * dir * rot.y;
	cam->sideway.y = cam->sideway.x * dir * rot.y + cam->sideway.y * rot.x;
}

void	move(t_camera *cam, int to, int dir)
{
	float	k;

	k = 0.08;
	print_vect(cam->sideway, "sideway vect");
	if (to == FORWARD)
	{
		cam->pos.x += dir * k * cam->dir.x;
		cam->pos.y += dir * k * cam->dir.y;
	}
	else
	{
		cam->pos.x += dir * k * cam->sideway.x;
		cam->pos.y += dir * k * cam->sideway.y;
	}
	print_vect(cam->pos, "new_pos");
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
		move(&d->cam, FORWARD, 1);
	else if (key == K_S)
		move(&d->cam, FORWARD, -1);
	else if (key == K_A)
		move(&d->cam, SIDEWAY, 1);
	else if (key == K_D)
		move(&d->cam, SIDEWAY, -1);
	else if (key == K_ESC)
		return (destroy(d), exit(0), 1);
	else
		return (0);
	//draw_minimap(d);
	render_scene(d);
	//mlx_put_image_to_window(d->mlx, d->win, d->minimap.img, 0, 0);
	return (0);
}
