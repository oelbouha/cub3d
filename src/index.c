/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:00:09 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/13 13:28:53 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_house(t_data *d)
{
	(void)d;
	return (0);
}

int	init(t_data *d)
{
	ft_bzero(d, sizeof (t_data));
	d->mlx = mlx_init();
	if (d->mlx == NULL)
		return (1);
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, TITLE);
	if (d->win == NULL)
		return (1);
	d->view.w = WIDTH;
	d->view.h = HEIGHT;
	if (init_canvas(d, &d->view))
		return (1);
	if (init_minimap(d) || init_house(d))
		return (1);
	d->cam.pos = (t_vect){.x = 3, .y = 2};
	d->cam.dir = (t_vect){.x = 1, .y = 0};
	d->cam.dir = (t_vect){.x = 0, .y = 0.66};
	return (0);
}

void	destroy(t_data *d)
{
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->view.img)
		mlx_destroy_image(d->mlx, d->view.img);
	if (d->minimap.img)
		mlx_destroy_image(d->mlx, d->view.img);
	free(d->mlx);
}

char	**get_map(void)
{
	char	**map = malloc(6 * sizeof(char *));
	map[0] = ft_strdup("11111");
	map[1] = ft_strdup("10001");
	map[2] = ft_strdup("10N01");
	map[3] = ft_strdup("10001");
	map[4] = ft_strdup("11111");
	map[5] = NULL;
	return (map);
}

int	main(int c, char **v)
{
	t_data	d;
	(void)c;
	(void)v;
	
	if (init(&d))
		return (destroy(&d), 77);
	d.house.map = get_map();
	d.house.w = ft_strlen(d.house.map[0]);
	d.house.h = 5;
	d.cam.pos = (t_vect){.x = 2.5, .y = 2.5};
	d.cam.dir = (t_vect){.x = 1.0, .y = 0};

	for (int i = 0; d.house.map[i]; i++)
		printf("%s\n", d.house.map[i]);
	printf("\n");

	//t_vect ray = {.x = -1.0, .y = 0.0};
	//raycaster(&d, d.cam.pos, ray);

	draw_minimap(&d);
	mlx_loop(d.mlx);
	return (0);
}
