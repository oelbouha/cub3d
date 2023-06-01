/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:19:49 by ysalmi            #+#    #+#             */
/*   Updated: 2023/05/31 21:54:36 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	pers(t_canvas *c)
{
	double	dy;

	dy = 0.15;

	for (int y = 0; y < c->h; y++)
	{
		for (int x = 0; x < c->w; x++)
		{
			if (x < 20)
				continue ;
			else if (x > 230)
				break ;
			else if (y < dy * x)
				continue ;
			else if (y > 200 - dy * x)
				continue ;
			paint_pxl(c, x, y, 0x00fff000);
		}
	}
}

int	main(void)
{
	t_data		d;
	t_canvas	c, s;

	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, WIDTH, HEIGHT, "Test");
	s.img = mlx_xpm_file_to_image(d.mlx, "./src/file1050x700.xpm", &s.w, &s.h);
	s.addr = mlx_get_data_addr(s.img, &s.bpp, &s.line_len, &s.endian);
	c.h = HEIGHT;
	c.w = WIDTH;
	init_canvas(&d, &c);
	paint_canvas(&c, 0xff123456);
	printf("loop\n");
	for (int x = 0; x < s.w && 2 * x < c.w; x++)
	{
		for (int y = 0; y < s.h && 2 * y < c.h; y++)
		{
			int s11 = get_pxl_color(&s, x, y);
			//int	s12 = get_pxl_color(&s, x + 1, y);
			//int s21 = get_pxl_color(&s, x, y + 1);
			//int	s22 = get_pxl_color(&s, x + 1, y + 1);
			//int	color = s11/4 + s12/4 + s21/4 + s22/4;
			int color = s11;
			paint_pxl(&c, 2 * x, 2 * y, color);
			paint_pxl(&c, 2 * x + 1, 2 * y, color);
			paint_pxl(&c, 2 * x, 2 * y + 1, color);
			paint_pxl(&c, 2 * x + 1, 2 * y + 1, color);
		}
	}
	pers(&c);
	mlx_put_image_to_window(d.mlx, d.win, c.img, 0, 0);
	mlx_loop(d.mlx);
}
