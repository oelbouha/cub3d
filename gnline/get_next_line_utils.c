/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:31:53 by oelbouha          #+#    #+#             */
/*   Updated: 2022/11/07 12:59:14 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concat(char *s1, char *s2)
{
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j] && s2[j] != '\n')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	if (s2[j] == '\n')
		s1[i++] = s2[j];
	s1[i] = '\0';
	return (s1);
}

char	*copy_to_rest(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	i++;
	j = 0;
	while (src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dst, char *src, int n)
{
	int		i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
