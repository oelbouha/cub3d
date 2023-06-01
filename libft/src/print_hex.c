/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:35:09 by ysalmi            #+#    #+#             */
/*   Updated: 2023/01/28 12:03:56 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	res(int r, int pre, int p);

int	print_hex(t_syntax syntax, int n)
{
	unsigned int	num;
	int				reserved;
	int				prepended;
	int				padded;
	int				precision;

	num = (unsigned long) n;
	precision = syntax.precision;
	reserved = get_num_hex_length(num) * (n != 0 || precision != 0);
	prepended = ((ft_strchr(syntax.flags, '#') != 0) && (num != 0));
	padded = ft_pad_left(syntax, res(reserved, prepended, syntax.precision));
	if (prepended && syntax.type == 'x')
		ft_putstr_fd("0x", 1);
	if (prepended && syntax.type == 'X')
		ft_putstr_fd("0X", 1);
	while (precision-- > reserved)
		ft_putchar_fd('0', 1);
	if (syntax.precision != 0 || num)
		print_num_in_hex(num, syntax.type == 'X');
	padded += ft_pad_right(syntax, res(reserved, prepended, syntax.precision));
	if (padded)
		return (syntax.width);
	return (res(reserved, prepended, syntax.precision));
}

static int	res(int r, int pre, int p)
{
	if (r > p)
		return (r + 2 * pre);
	return (p + 2 * pre);
}
