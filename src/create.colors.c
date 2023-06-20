/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:54:10 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/20 11:50:41 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	is_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	valid_number(char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
	{
		if (!is_number(arr[i]) || ft_atoi(arr[i]) > 255)
			return (0);
	}
	return (1);
}

int	create_colors(char *line, t_house *house)
{
	char	**arr;
	int		ret;
	char	*trimed;
	char	*color;

	arr = NULL;
	trimed = ft_strtrim(line, " ");
	color = skip_spaces(&trimed[2]);
	arr = ft_split(color, ',');
	if (arr == NULL)
		return (free(trimed), 1);
	if (!valid_number(arr))
	{
		print_error_msg("not a valid number");
		return (free(trimed), free_arr(arr), 1);
	}
	ret = ft_strnmatch(line, "F:C", ':', 1);
	if (ret == 1)
		house->floor = rgb(ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2]));
	else if (ret == 2)
		house->ceiling = rgb(ft_atoi(*arr), ft_atoi(arr[1]), ft_atoi(arr[2]));
	return (free_arr(arr), free(line), free(trimed), 0);
}