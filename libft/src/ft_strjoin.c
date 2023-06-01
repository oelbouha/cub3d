/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:21:19 by ysalmi            #+#    #+#             */
/*   Updated: 2023/05/18 13:17:53 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s;
	int		s1_len;
	int		s2_len;
	int		i;

	if (!s2)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	s = malloc(s1_len + s2_len + 1);
	if (!s)
		return (0);
	while (i < s1_len + s2_len)
	{
		if (i < s1_len)
			s[i] = s1[i];
		else
			s[i] = s2[i - s1_len];
		i++;
	}
	s[i] = 0;
	return (s);
}
