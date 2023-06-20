/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:11:09 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/20 11:50:56 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_textures(t_house *house, char **map)
{
	if(house->south.img == NULL || house->north.img == NULL || map == NULL)
		return (1);
	if (house->east.img == NULL || house->west.img == NULL)
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

int	analyze_textures(t_house *house, t_data *data)
{
	if (check_textures(house, house->map))
		return (destroy_textures(house, data), 1);
	return (0);		
}
