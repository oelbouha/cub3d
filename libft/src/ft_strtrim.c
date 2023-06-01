/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:28:47 by ysalmi            #+#    #+#             */
/*   Updated: 2022/10/01 12:47:53 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	contains(const char *s, char c);

char	*ft_strtrim(const char *s, const char *set)
{
	int	len;
	int	start;
	int	i;

	if (!s)
		return (0);
	i = -1;
	start = 0;
	while (s[++i] && contains(set, s[i]))
		start = i + 1;
	i = ft_strlen(s);
	len = i - start;
	while (s[--i] && contains(set, s[i]) && i >= start)
		len = i - start;
	return (ft_substr(s, start, len));
}

static int	contains(const char *s, char c)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}
