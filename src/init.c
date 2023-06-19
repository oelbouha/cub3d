/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:00:09 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/19 10:08:11 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_house(t_data *d)
{
	(void)d;
	return (0);
}

t_data	*init(void)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (d == NULL)
		return (NULL);
	ft_bzero(d, sizeof (t_data));
	d->mlx = mlx_init();
	if (d->mlx == NULL)
		return (destroy(d), NULL);
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, TITLE);
	if (d->win == NULL)
		return (destroy(d), NULL);
	d->view.w = WIDTH;
	d->view.h = HEIGHT;
	if (init_canvas(d, &d->view))
		return (destroy(d), NULL);
	if (init_minimap(d) || init_house(d))
		return (destroy(d), NULL);
	d->cam.pos = (t_vect){.x = 3, .y = 2};
	d->cam.dir = (t_vect){.x = 1, .y = 0};
	d->cam.plane = (t_vect){.x = 0, .y = 0.66};
	return (d);
}

void	destroy(t_data *d)
{
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	printf("win destroyed\n");
	if (d->view.img)
		mlx_destroy_image(d->mlx, d->view.img);
	printf("view destroyed\n");
	if (d->minimap.img)
		mlx_destroy_image(d->mlx, d->minimap.img);
	printf("minimap destroyed\n");
	free(d->mlx);
}
