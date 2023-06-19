/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:00:09 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/19 13:10:59 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**get_map(void)
{
	char	**map = malloc(6 * sizeof(char *));
	map[0] = ft_strdup("11111");
	map[1] = ft_strdup("10001");
	map[2] = ft_strdup("10101");
	map[3] = ft_strdup("10001");
	map[4] = ft_strdup("11111");
	map[5] = NULL;
	return (map);
}

int	main(int c, char **v)
{
	t_data	*d;
	(void)c;
	(void)v;
	
	d = init();
	if (d == NULL)
		return (77);
	d->house.map = get_map();
	d->house.w = ft_strlen(d->house.map[0]);
	d->house.h = 5;
	d->cam.pos = (t_vect){.x = 3.5, .y = 2.5};
	d->cam.dir = (t_vect){.x = -1.0, .y = 0};
	d->cam.plane = (t_vect){.x = 0, .y = -0.66};

	for (int i = 0; d->house.map[i]; i++)
		printf("%s\n", d->house.map[i]);
	printf("\n");

	if (0)
	{
		t_hit	hit;
		d->cam.pos = (t_vect){.x = 2.5, .y = 1.8};
		t_vect ray = {.x = -1.0, .y = 0.66};
		hit = raycaster(d, d->cam.pos, ray);
		{
			switch(hit.side)
			{
				case TOP:
					printf("hit.side:\tTop\n");
					break;
				case BOTTOM:
					printf("hit.side:\tBottom\n");
					break;
				case LEFT:
					printf("hit.side:\tLeft\n");
					break;
				case RIGHT:
					printf("hit.side:\tRight\n");
					break;
			}
			printf("hit.l_height:\t%d\n", hit.line_height);
			printf("hit.start:\t%d\n", hit.draw_start);
			printf("hit.dist:\t%f\n", hit.wall_dist);
			printf("hit.pos:\t%f\n", hit.wall_pos);
			print_vect(hit.dist, "dist");
		}
	}
	else if (1)
	{
		draw_minimap(d);
		render_scene(d);
		mlx_put_image_to_window(d->mlx, d->win, d->minimap.img, 0, 0);
		mlx_key_hook(d->win, keydown_handler, d);
		mlx_loop(d->mlx);
	}
	else
	{
		draw_minimap(d);
		mlx_loop(d->mlx);
	}
	return (0);
}
