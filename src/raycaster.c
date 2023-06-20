/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:27:10 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/20 10:02:05 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define LARGE_NUMBER 10000000

t_ray	new_ray(t_vect pos, t_vect ray)
{
	t_ray	r;

	r.step = (t_vect_i){.x = 1 - 2 * (ray.x < 0), .y = 1 - 2 * (ray.y < 0)};
	r.yl = (t_vect){.x = 0, .y = pos.y};
	r.xl = (t_vect){.x = 0, .y = pos.x};
	if (ray.x)
		r.yl = (t_vect){.x = ray.y / ray.x,
			.y = pos.y - (ray.y / ray.x) * pos.x};
	if (ray.y)
		r.xl = (t_vect){.x = ray.x / ray.y,
			.y = pos.x - (ray.x / ray.y) * pos.y};
	r.dist = (t_vect){.x = LARGE_NUMBER, .y = LARGE_NUMBER};
	if (ray.y != 0)
		r.dist.x = r.xl.x * ((int)(pos.y + (r.step.y > 0))) + r.xl.y;
	if (ray.x != 0)
		r.dist.y = r.yl.x * ((int)(pos.x + (r.step.x > 0))) + r.yl.y;
	return (r);
}

void	stepx(char **map, t_hit *h, t_vect_i *coords, t_ray *r)
{
	int	done;

	done = 0;
	while (!done)
	{
		while (coords->x != (int)r->dist.x)
		{
			coords->x += r->step.x;
			if (map[coords->y][coords->x] == '1')
			{
				h->side = 0;
				done = 1;
				break ;
			}
		}
		if (done)
			break ;
		coords->y += r->step.y;
		if (map[coords->y][coords->x] == '1')
		{
			h->side = 1;
			done = 1;
		}
		r->dist.x += r->step.x * fabs(r->xl.x);
	}
}

void	stepy(char **map, t_hit *h, t_vect_i *coords, t_ray *r)
{
	int	done;

	done = 0;
	while (!done)
	{
		while (coords->y != (int)r->dist.y)
		{
			coords->y += r->step.y;
			if (map[coords->y][coords->x] == '1')
			{
				h->side = 1;
				done = 1;
				break ;
			}
		}
		if (done)
			break ;
		coords->x += r->step.x;
		if (map[coords->y][coords->x] == '1')
		{
			h->side = 0;
			done = 1;
		}
		r->dist.y += r->step.y * fabs(r->yl.x);
	}
}

void	adjust(t_hit *h, t_ray *r, t_vect_i coords)
{
	if (h->side == 1)
	{
		r->dist.y = coords.y + (r->step.y < 0);
		r->dist.x = r->xl.x * r->dist.y + r->xl.y;
		h->side = TOP * (r->step.y > 0) + BOTTOM * (r->step.y < 0);
		h->wall_pos = r->dist.x - (int)r->dist.x;
	}
	else
	{
		r->dist.x = coords.x + (r->step.x < 0);
		r->dist.y = r->yl.x * r->dist.x + r->yl.y;
		h->side = LEFT * (r->step.x > 0) + RIGHT * (r->step.x < 0);
		h->wall_pos = r->dist.y - ((int)r->dist.y);
	}
}

t_hit	raycaster(t_data *d, t_vect pos, t_vect ray)
{
	t_hit		h;
	t_ray		r;
	t_vect_i	coords;

	ft_bzero(&h, sizeof(t_hit));
	coords = (t_vect_i){.x = (int) pos.x, .y = (int) pos.y};
	r = new_ray(pos, ray);
	if (fabs(r.xl.x) >= fabs(r.yl.x))
		stepx(d->house.map, &h, &coords, &r);
	else
		stepy(d->house.map, &h, &coords, &r);
	adjust(&h, &r, coords);
	h.dist = r.dist;
	r.dist.x -= pos.x;
	r.dist.y -= pos.y;
	h.wall_dist = r.dist.x * d->cam.dir.x + r.dist.y * d->cam.dir.y;
	h.line_height = 0.5 * HEIGHT / h.wall_dist;
	h.draw_start = (HEIGHT / 2) - (h.line_height / 2);
	h.draw_end = (HEIGHT / 2) + (h.line_height / 2);
	return (h);
}
