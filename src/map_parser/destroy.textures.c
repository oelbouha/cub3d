/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:11:09 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/07 22:11:30 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	destroy_north_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->house.north.img);
	return (1);
}

int	destroy_south_img(t_data *data)
{
	destroy_north_img(data);
	mlx_destroy_image(data->mlx, data->house.south.img);
	return (1);
}

int	destroy_west_img(t_data *data)
{
	destroy_south_img(data);
	mlx_destroy_image(data->mlx, data->house.west.img);
	return (1);
}