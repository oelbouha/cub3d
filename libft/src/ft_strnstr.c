/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:39:43 by ysalmi            #+#    #+#             */
/*   Updated: 2022/09/29 15:14:35 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	if (! *little)
		return ((char *)big);
	i = -1;
	while (++i < n && big[i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[++j] && big[i + j] == little[j] && i + j < n)
				;
			if (! little[j])
				return ((char *)&big[i]);
		}
	}
	return (0);
}
