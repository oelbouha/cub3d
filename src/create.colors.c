/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:54:10 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/22 13:24:19 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	check_color(char *str)
{
	int	i;

	if (*str == ',' || str[ft_strlen(str) - 1] == ',')
		return (1);
	i = -1;
	while (str[++i])
	{
		if (str[i] == ',' && str[i + 1] == ',')
			return (1);
	}
	return (0);
}

int	valid_number(char **arr, char *line)
{
	char	*str;
	int		i;
	int		j;

	if (arr_len(arr) != 3 || check_color(line))
		return (0);
	i = -1;
	while (arr[++i])
	{
		str = skip_spaces(arr[i]);
		j = 0;
		while (str[j] && ft_isdigit(str[j]))
			j++;
		if (j > 3 || j == 0 || ft_atoi(str) > 255 || ft_atoi(str) < 0)
			return (0);
		str = skip_spaces(&str[j]);
		if (*str != 0)
			return (0);
	}
	return (1);
}

int	convert_number_to_rgb(int n, char **arr, t_house *h)
{
	if (n == 1)
	{
		if (h->floor != -1)
		{
			print_error_msg("floor color is duplicated");
			return (1);
		}
		h->floor = rgb(ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2]));
	}
	else if (n == 2)
	{
		if (h->ceiling != -1)
		{
			print_error_msg("ceiling color is duplicated");
			return (1);
		}
		h->ceiling = rgb(ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2]));
	}
	return (0);
}

int	create_colors(char *line, t_house *h)
{
	char	**arr;
	int		ret;
	int		n;
	char	*trimed;
	char	*color;

	ret = 0;
	arr = NULL;
	trimed = ft_strtrim(line, " ");
	color = skip_spaces(&trimed[1]);
	arr = ft_split(color, ',');
	if (arr == NULL)
		return (free(trimed), free(line), 1);
	if (!valid_number(arr, color))
	{
		print_error_msg("not a valid color");
		return (free(trimed), free_arr(arr), free(line), 1);
	}
	n = ft_strnmatch(trimed, "F:C", ':', 1);
	ret = convert_number_to_rgb(n, arr, h);
	return (free_arr(arr), free(line), free(trimed), ret);
}
