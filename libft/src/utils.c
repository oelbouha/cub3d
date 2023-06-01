/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:03:54 by ysalmi            #+#    #+#             */
/*   Updated: 2022/11/26 12:40:34 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_num_length(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	get_num_hex_length(unsigned long n)
{
	int	len;

	len = 1;
	while (n / 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	print_num_in_hex(unsigned long n, int uppercase)
{
	char	*base;
	int		r;

	base = "0123456789abcdef";
	if (uppercase)
		base = "0123456789ABCDEF";
	r = 1;
	if (n / 16)
		r += print_num_in_hex(n / 16, uppercase);
	ft_putchar_fd(base[n % 16], 1);
	return (r);
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}
