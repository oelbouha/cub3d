/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:15:59 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/20 11:51:51 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_a_texture(char *str, int len)
{
	if (ft_strnstr(str, "NO", len) || ft_strnstr(str, "SO", len)
		|| ft_strnstr(str, "WE", len) || ft_strnstr(str, "EA", len))
		return (1);
	return (0);
}

int	is_a_color(char *str)
{
	if (ft_strchr(str, 'F') || ft_strchr(str, 'C'))
		return (1);
	return (0);
}

int	check_line(t_house *house, t_data *data, t_list **lst, char *trimed)
{
	t_list	*node;
	int		ret;

	ret = 0;
	if (is_a_texture(trimed, ft_strlen(trimed)))
		ret = open_textures(trimed, house, data);
	else if (is_a_color(trimed))
		ret = create_colors(trimed, house);
	else
	{
		node = ft_lstnew(trimed);
		if (node == NULL)
			return (1);
		ft_lstadd_back(lst, node);
	}
	return (ret);
}

t_house	parse_map(char *file, t_data data)
{
	t_house		house;
	t_list		*lst;
	char		*trimed;
	char		*line;
	int			fd;

	lst = NULL;
	ft_bzero(&house, sizeof(t_house));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (house);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		trimed = ft_strtrim(line, "\n");
		if (check_line(&house, &data, &lst, trimed))
			return (free(line), ft_lstclear(&lst, free), house);
		free(line);
	}
	if (analyze_map(lst))
		return (ft_lstclear(&lst, free), house);
	house.map = get_rectangle_map(lst);
	return (ft_lstclear(&lst, free), house);
}
