/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:00:09 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/20 23:34:57 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_house(t_data *d, char *map_path)
{
	d->house = parse_map(map_path , *d);
	if (d->house.map == NULL)
		return (1);
	if (!is_map_enclosed(&d->house))
		return (ft_putendl_fd("Map is not surounded by walls", 2), 1);
	init_player(d);
	return (0);
}

t_data	*init(char *map_path)
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
	if (init_minimap(d) || init_house(d, map_path))
		return (destroy(d), NULL);
	return (d);
}

void	destroy(t_data *d)
{
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->view.img)
		mlx_destroy_image(d->mlx, d->view.img);
	if (d->minimap.img)
		mlx_destroy_image(d->mlx, d->minimap.img);
	destroy_textures(&d->house, d); 
	free(d->mlx);
}
