/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:00:09 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/20 13:00:55 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int c, char **v)
{
	t_data	*d;
	
	if (c != 2)
		return (1);
	d = init(v[1]);
	if (d == NULL)
		return (77);
	mlx_do_key_autorepeaton(d->mlx);
	//draw_minimap(d);
	render_scene(d);
	//mlx_put_image_to_window(d->mlx, d->win, d->minimap.img, 0, 0);
	mlx_key_hook(d->win, keydown_handler, d);
	mlx_loop(d->mlx);
	return (0);
}
