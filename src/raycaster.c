/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:27:10 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/12 18:34:02 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define LARGE_NUMBER 1000000000000

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

	ft_bzero(&hit, sizeof(t_hit));
	coords = (t_vect_i){.x = (int) pos.x, .y = (int) pos.y};
	step = (t_vect_i){.x = 1 - 2 * (ray.x < 0), .y = 1 - 2 * (ray.y < 0)};

	yl = (t_vect){.x = 0, .y = pos.y};
	xl = (t_vect){.x = 0, .y = pos.x};
	if (ray.x)
		yl = (t_vect){.x = ray.y / ray.x, .y = pos.y - (ray.y / ray.x) * pos.x};
	if (ray.y)
		xl = (t_vect){.x = ray.x / ray.y, .y = pos.x - (ray.x / ray.y) * pos.y};

	printf("next y: %d\n",((int)(pos.y + step.y * (step.y > 0))));
	dist = (t_vect){.x = LARGE_NUMBER, .y = LARGE_NUMBER};
	if (ray.y != 0)
		dist.x = xl.x * ((int)(pos.y + step.y * (step.y > 0))) + xl.y;
	if (ray.x != 0)
		dist.y = yl.x * ((int)(pos.x + step.x * (step.x > 0))) + yl.y;

	print_vect_i(coords, "coords");
	print_vect_i(step, "step");
	print_vect(ray, "ray");
	print_vect(pos, "pos");
	print_vect(yl, "y(x)");
	print_vect(xl, "x(y)");
	print_vect(dist, "dist to next col/row");
	//t_vect diff = (t_vect){.x = coords.x - (int)dist.x, .y = coords.y - (int)dist.y};
	//print_vect(diff, "diff");
	
	if (abs(coords.x - (int)dist.x) >= abs(coords.y - (int)dist.y))
		coords.x += step.x;
	else
		coords.y += step.y;

	print_vect_i(coords, "coords");

	printf("loop:\n");
	while (d->house.map[coords.y][coords.x] != '1')
	{
		if ((int)dist.x > step.x * coords.x)
		{
			dist.y += fabs(yl.x) * step.y;
			coords.x += step.x;
			hit.side = 0;
			printf("x.");
		}
		else
		{
			dist.x += fabs(xl.x) * step.x;
			coords.y += step.y;
			hit.side = 1;
			printf("y.");
		}
		printf("map[%d][%d]: [%c]\n", coords.y, coords.x, d->house.map[coords.y][coords.x]);
	}
	printf("\b\n");
	print_vect_i(coords, "coords");
	print_vect(dist, "dist to next col/row");

	if (hit.side == 1)
	{
		dist.y = coords.y + (step.y < 0);
		if (xl.x)
			dist.x = xl.x * dist.y + xl.y;
	}
	else
	{
		dist.x = coords.x + (step.x < 0);
		if (yl.x)
			dist.y = yl.x * dist.x + yl.y;
	}


	{
		if (hit.side == 0 && step.x > 0)
			printf("left\n");
		else if (hit.side == 0 && step.x < 0)
			printf("right\n");
		else if (hit.side == 1 && step.y > 0)
			printf("top\n");
		else
			printf("bottom\n");
	}
	
	print_vect(dist, "dist to next col/row");

	printf("perpdist = %d\n", 1);
	return (hit);
}
//
// hit.side
// 	0: facing down	v
// 	1: facing up	^
// 	2: facing right	>
// 	3: facing left	<
