/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:23:27 by ysalmi            #+#    #+#             */
/*   Updated: 2022/09/30 17:37:50 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (str[++i])
		if (str[i] == c)
			j = i;
	if (j > -1)
		return ((char *) &str[j]);
	if (c == 0)
		return ((char *)&str[i]);
	return (0);
}
