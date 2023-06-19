/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:30:59 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/19 13:01:11 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint_pxl(t_canvas *c, int x, int y, int color)
{
	char	*pxl_addr;

	pxl_addr = c->addr + (y * c->line_len + x * (c->bpp / 8));
	*(unsigned int *)pxl_addr = color;
}

int	get_pxl_color(t_canvas *c, int x, int y)
{
	char	*pxl_addr;
	int		*pxl_address;
	int		color;

	pxl_addr = c->addr + (y * c->line_len + x * (c->bpp / 8));
	pxl_address = (int *)pxl_addr;
	color = *pxl_address;
	return (color);
}

int	init_canvas(t_data *data, t_canvas *c)
{
	c->img = mlx_new_image(data->mlx, c->w, c->h);
	if (!c->img)
		return (1);
	c->addr = mlx_get_data_addr(c->img, &c->bpp, &c->line_len, &c->endian);
	return (0);
}

void	draw_in_canvas(t_canvas *c, void (*pxl)(t_canvas *, int, int))
{
	int	x;
	int	y;

	x = -1;
	while (++x < c->w)
	{
		y = -1;
		while (++y < c->h)
		{
			pxl(c, x, y);
		}
	}
}

void	paint_canvas(t_canvas *c, int color)
{
	int	x;
	int	y;

	x = -1;
	while (++x < c->w)
	{
		y = -1;
		while (++y < c->h)
		{
			paint_pxl(c, x, y, color);
		}
	}
}
