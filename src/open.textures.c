/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:54:40 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/22 13:32:09 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_south_and_north(int ret, t_house *house, char *filename, void *mlx)
{
	t_canvas	*c;

	c = NULL;
	if (ret == NORTH)
		c = &house->north;
	else if (ret == SOUTH)
		c = &house->south;
	if (c->img)
		return (print_error_msg("duplicated texture"), 1);
	c->img = mlx_xpm_file_to_image(mlx, filename, &c->w, &c->h);
	if (c->img == NULL)
		return (print_error_msg("failed to open textures"), 1);
	c->addr = mlx_get_data_addr(c->img, &c->bpp, &c->line_len, &c->endian);
	return (0);
}

int	open_east_and_west(int ret, t_house *house, char *filename, void *mlx)
{
	t_canvas	*c;

	c = NULL;
	if (ret == WEST)
		c = &house->west;
	else if (ret == EAST)
		c = &house->east;
	if (c->img)
		return (print_error_msg("duplicated texture"), 1);
	c->img = mlx_xpm_file_to_image(mlx, filename, &c->w, &c->h);
	if (c->img == NULL)
		return (print_error_msg("failed to open textures"), 1);
	c->addr = mlx_get_data_addr(c->img, &c->bpp, &c->line_len, &c->endian);
	return (0);
}

int	open_textures(char *line, t_house *house, t_data *data)
{
	char	*trimed;
	char	*filename;
	int		ret;
	int		n;

	ret = 0;
	trimed = ft_strtrim(line, " ");
	if (trimed[2] != ' ')
	{
		print_error_msg("not a valid texture path");
		return (free(trimed), free(line), 1);
	}
	n = ft_strnmatch(trimed, "NO:SO:WE:EA", ':', 2);
	filename = skip_spaces(&trimed[2]);
	free(line);
	if (n == NORTH || n == SOUTH)
		ret = open_south_and_north(n, house, filename, data->mlx);
	else if (n == WEST || n == EAST)
		ret = open_east_and_west(n, house, filename, data->mlx);
	return (free(trimed), ret);
}
