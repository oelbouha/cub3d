/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:11:09 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/21 09:15:40 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_textures(t_house *h)
{
	if (!h->north.img || !h->east.img || !h->west.img || !h->south.img)
		return (1);
	return (0);	
}

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
