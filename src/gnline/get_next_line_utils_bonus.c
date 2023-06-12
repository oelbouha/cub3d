/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:31:53 by oelbouha          #+#    #+#             */
/*   Updated: 2022/11/14 08:32:26 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
	while (src[i] != '\n')
		i++;
	i++;
	j = 0;
	while (src[i])
	{
		dest[j] = src[i];
		j++;
	i++;
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}
