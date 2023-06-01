/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:55:40 by ysalmi            #+#    #+#             */
/*   Updated: 2022/09/30 20:14:43 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	nb;
	int				len;

	nb = n * (n > 0) - n * (n < 0);
	len = 1 + 1 * (n < 0);
	while (nb / 10)
	{
		nb /= 10;
		len++;
	}
	s = malloc(len + 1);
	if (! s)
		return (0);
	s[len--] = 0;
	s[0] = '-' * (n < 0);
	nb = n * (n > 0) - n * (n < 0);
	while (nb / 10)
	{
		s[len--] = nb % 10 + 48;
		nb /= 10;
	}
	s[len] = nb % 10 + 48;
	return (s);
}
