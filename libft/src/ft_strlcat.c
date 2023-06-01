/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:09:34 by ysalmi            #+#    #+#             */
/*   Updated: 2022/10/02 10:55:05 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	src_len;
	int	dst_len;
	int	i;

	src_len = ft_strlen(src);
	if (!dst && !size)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (!size || (size_t) dst_len >= size)
		return (src_len + size);
	i = 0;
	while (dst[i])
		i++;
	while (src[i - dst_len] && (size_t) i < size - 1)
	{
		dst[i] = src[i - dst_len];
		i++;
	}
	dst[i] = 0;
	return (src_len + dst_len);
}
