/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:43:26 by ysalmi            #+#    #+#             */
/*   Updated: 2022/09/30 15:37:08 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;

	dup = malloc(ft_strlen(str) + 1);
	if (!dup)
		return (0);
	i = -1;
	while (str[++i])
		dup[i] = (char)str[i];
	dup[i] = 0;
	return (dup);
}
