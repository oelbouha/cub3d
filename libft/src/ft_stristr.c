/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stristr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:51:29 by ysalmi            #+#    #+#             */
/*   Updated: 2023/04/12 15:07:06 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stristr(const char *big, const char *little)
{
	int	i;
	int	j;

	if (! *little)
		return ((char *)big);
	i = -1;
	while (big[++i])
	{
		j = 0;
		while (little[j] && ft_tolower(little[j]) == ft_tolower(big[i + j]))
			j++;
		if (little[j] == 0)
			return ((char *) &big[i]);
	}
	return ((char *)0);
}
