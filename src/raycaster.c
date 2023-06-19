/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:27:10 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/19 12:07:03 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define LARGE_NUMBER 10000000

int	abs(int n)
{
	return (n * (n > 0) - n * (n < 0));
}



t_hit	raycaster(t_data *d, t_vect pos, t_vect ray)
{
	t_hit		hit;
	t_vect		yl;
	t_vect		xl;
	t_vect_i	coords;
	t_vect_i	step;
	t_vect		dist;

	(void)d;
	int	debug = 0;

	ft_bzero(&hit, sizeof(t_hit));
	coords = (t_vect_i){.x = (int) pos.x, .y = (int) pos.y};
	step = (t_vect_i){.x = 1 - 2 * (ray.x < 0), .y = 1 - 2 * (ray.y < 0)};

	/****		Init		****/
	/***************************/
	yl = (t_vect){.x = 0, .y = pos.y};
	xl = (t_vect){.x = 0, .y = pos.x};
	if (ray.x)
		yl = (t_vect){.x = ray.y / ray.x, .y = pos.y - (ray.y / ray.x) * pos.x};
	if (ray.y)
		xl = (t_vect){.x = ray.x / ray.y, .y = pos.x - (ray.x / ray.y) * pos.y};

	dist = (t_vect){.x = LARGE_NUMBER, .y = LARGE_NUMBER};
	if (ray.y != 0)
		dist.x = xl.x * ((int)(pos.y + (step.y > 0))) + xl.y;
	if (ray.x != 0)
		dist.y = yl.x * ((int)(pos.x + (step.x > 0))) + yl.y;

	if (debug)
	{
		print_vect(pos, "pos");
		print_vect(yl, "y[x]");
		print_vect(xl, "x[y]");
	}

	/****		dist		****/
	/***************************/
	int	done = 0;
	//if (abs(coords.x - (int)dist.x) >= abs(coords.y - (int)dist.y))
	if (fabs(xl.x) >= fabs(yl.x))
	{/****	if x changes faster than y	****/
		while (!done)
		{
			while (coords.x != (int)dist.x)
			{
				coords.x += step.x;
				if (d->house.map[coords.y][coords.x] == '1')
				{
					hit.side = 0;
					done = 1;
					break ;
				}
			}
			if (!done)
			{
				coords.y += step.y;
				if (d->house.map[coords.y][coords.x] == '1')
				{
					hit.side = 1;
					done = 1;
				}
				dist.x += step.x * fabs(xl.x);
			}
		}
	}
	else
	{/****	if y changes faster than x	****/
		while (!done)
		{
			while (coords.y != (int)dist.y)
			{
				coords.y += step.y;
				if (d->house.map[coords.y][coords.x] == '1')
				{
					hit.side = 1;
					done = 1;
					break ;
				}
			}
			if (!done)
			{
				coords.x += step.x;
				if (d->house.map[coords.y][coords.x] == '1')
				{
					hit.side = 0;
					done = 1;
				}
				dist.y += step.y * fabs(yl.x);
			}
		}
	}

	/****	Adjust dist		****/
	if (hit.side == 1)
	{
		dist.y = coords.y + (step.y < 0);
		dist.x = xl.x * dist.y + xl.y;
		hit.side = TOP * (step.y > 0) + BOTTOM * (step.y < 0);
		hit.wall_pos = dist.x - (int)dist.x;
	}
	else
	{
		dist.x = coords.x + (step.x < 0);
		dist.y = yl.x * dist.x + yl.y;
		hit.side = LEFT * (step.x > 0) + RIGHT * (step.x < 0);
		hit.wall_pos = dist.y - ((int)dist.y);
	}
	hit.dist = dist;
	dist.x -= pos.x;
	dist.y -= pos.y;
	hit.wall_dist = dist.x * d->cam.dir.x + dist.y * d->cam.dir.y;
	hit.line_height = 0.5 *  HEIGHT / hit.wall_dist;
	hit.draw_start = (HEIGHT / 2) - (hit.line_height / 2);
	
	return (hit);
}
