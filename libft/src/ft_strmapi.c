/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:35:37 by ysalmi            #+#    #+#             */
/*   Updated: 2022/10/01 12:49:34 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	int		s_len;
	int		i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	new_s = malloc(s_len + 1);
	if (! new_s)
		return (0);
	i = -1;
	while (s[++i])
		new_s[i] = f(i, s[i]);
	new_s[i] = 0;
	return (new_s);
}
