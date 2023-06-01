/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:21:49 by ysalmi            #+#    #+#             */
/*   Updated: 2022/09/30 18:55:25 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nbr)
{
	int				sign;
	int				i;
	unsigned int	n;

	i = 0;
	while (nbr[i] == ' ' || (nbr[i] > 8 && nbr[i] < 14))
		i++;
	sign = 1 - 2 * (nbr[i] == '-');
	i += 1 * (sign < 0 || nbr[i] == '+');
	n = 0;
	while (nbr[i] > 47 && nbr[i] < 58)
		n = n * 10 + nbr[i++] - 48;
	return ((int)(sign * n));
}
