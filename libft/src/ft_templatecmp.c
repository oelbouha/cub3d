/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_templatecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:16:17 by ysalmi            #+#    #+#             */
/*   Updated: 2023/04/29 12:08:39 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_templatecmp(const char *str, const char *template, char delimiter)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	while (template[i])
	{
		if (ft_strncmp(str, &template[i], len) == 0)
			if (template[i + len] == delimiter || template[i + len] == 0)
				return (1);
		while (1)
		{
			if (template[i] == delimiter)
				break ;
			else if (template[i] == 0)
				return (0);
			i++;
		}
		i++;
	}
	return (0);
}
