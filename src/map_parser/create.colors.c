/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:54:10 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/09 12:06:06 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	int		r;
	int		g;
	int		b;

	arr = NULL;
	if (line[2] == ' ' || line[1] != ' ')
		return (print_error_msg("color error"), free_arr(arr), 1);
	arr = ft_split(&line[2], ',');
	if (arr == NULL)
		return (1);
	if (!valid_number(arr))
		return (ft_putstr_fd("not a valid number\n", 2), free_arr(arr), 1);
	r = ft_atoi(arr[0]);
	g = ft_atoi(arr[1]);
	b = ft_atoi(arr[2]);
	ret = ft_strnmatch(line, "F:C", ':', 1);
	if (ret == 1)
		house->floor = create_rgb(r, g, b);
	else if (ret == 2)
		house->ceiling = create_rgb(r, g, b);
	return (free_arr(arr), free(line), 0);
}