/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:54:40 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/09 15:13:48 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	open_textures(char *line, t_house *house, t_data *data)
{
	char	*filename;
	int		ret;

	if (line[2] != ' ' || line[3] == ' ')
		return (print_error_msg("syntax error in map"), 1);
	ret = ft_strnmatch(line, "NO:SO:WE:EA", ':', 2);
	filename = &line[3];
	if (ret == 1)
	{
		house->north.img = mlx_xpm_file_to_image(data->mlx, filename, &house->north.w, &house->north.h);
		if (house->north.img == NULL)
			return (print_error_msg("failed to open North textrue"), 1);
	}
	else if (ret == 2)
	{
		house->south.img = mlx_xpm_file_to_image(data->mlx, filename, &house->south.w, &house->south.h);
		if (house->south.img == NULL)
			return (print_error_msg("failed to open South textrue"), 1);
	}
	else if (ret == 3)
	{
		house->west.img = mlx_xpm_file_to_image(data->mlx, filename, &house->west.w, &house->west.h);
		if (house->west.img == NULL)
			return (print_error_msg("failed to open West textrue"), 1);
	}
	else if (ret == 4)
	{
		house->east.img = mlx_xpm_file_to_image(data->mlx, filename, &house->east.w, &house->east.h);
		if (house->east.img == NULL)
			return (print_error_msg("failed to open East textrue"), 1);
	}
	return (free(line), 0);
}