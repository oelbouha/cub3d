/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:11:09 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/20 23:13:17 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_textures(t_house *house, t_data *data)
{
	if (house->north.img)
		mlx_destroy_image(data->mlx, house->north.img);
	if (house->south.img)
		mlx_destroy_image(data->mlx, house->south.img);
	if (house->east.img)
		mlx_destroy_image(data->mlx, house->east.img);
	if (house->west.img)
		mlx_destroy_image(data->mlx, house->west.img);
	free_arr(house->map);
}
