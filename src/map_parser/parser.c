/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:15:59 by ysalmi            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/05 11:48:09 by ysalmi           ###   ########.fr       */
=======
/*   Updated: 2023/06/09 12:37:56 by oelbouha         ###   ########.fr       */
>>>>>>> 67e7479b9f8b2bd0282df78a17c0908217bb49f1
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_line(t_house *house, t_data *data, t_list **lst, char *trimed)
{
	t_list	*node;

	if (ft_strnmatch(trimed, "NO:SO:WE:EA", ':', 2))
	{
		if (open_textures(trimed, house, data))
			return (ft_lstclear(lst, free), 1);
	}
	else if (ft_strnmatch(trimed, "F:C", ':', 1))
	{
		if (create_colors(trimed, house))
			return (ft_lstclear(lst, free), 1);
	}
	else if (ft_issubset(" ", trimed) == 0)
	{
		node = ft_lstnew(trimed);
		if (node == NULL)
			return (ft_lstclear(lst, free), 1);
		ft_lstadd_back(lst, node);
	}
	else
		free(trimed);
	return (0);
}
<<<<<<< HEAD
/*
t_house	parse_map(char *file)
=======

t_house	parse_map(char *file, t_data data)
>>>>>>> 67e7479b9f8b2bd0282df78a17c0908217bb49f1
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
	house.map = get_rectangle_map(lst);
	return (ft_lstclear(&lst, free), house);
}
*/
