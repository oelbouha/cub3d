/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:15:59 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/02 12:37:35 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	strnmatch(const char *s, char *matches, char delimiter, int n)
{
	int		ret;

	ret = 1;
	while (matches)
	{
		if (ft_strncmp(s, matches, n) == 0 
			&& (*(matches + n) == delimiter || *(matches + n) == 0))
			return (ret);
		ret++;
		matches = ft_strchr(matches, delimiter);
		matches += matches != NULL;
	}
	return (0);
}

t_house	parse_map(char *file)
{
	t_house	house;
	int		fd;
	char	*line;

	ft_bzero(&house, sizeof(t_house));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (house);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
			break ;
		else if (strnmatch(line, "NO:SO:WE:EA", ':', 2))
	}
}
