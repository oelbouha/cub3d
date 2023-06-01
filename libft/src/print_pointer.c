/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:03:58 by ysalmi            #+#    #+#             */
/*   Updated: 2023/01/28 12:03:07 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_pointer(t_syntax syntax, void *p)
{
	unsigned long	pointer;
	int				reserved;
	int				padded;
	int				precision;

	pointer = (unsigned long) p;
	reserved = get_num_hex_length(pointer);
	precision = syntax.precision;
	padded = ft_pad_left(syntax, reserved + 2);
	ft_putstr_fd("0x", 1);
	while (precision-- > reserved)
		ft_putchar_fd('0', 1);
	print_num_in_hex(pointer, FALSE);
	padded += ft_pad_right(syntax, reserved + 2);
	if (padded)
		return (syntax.width);
	else if (syntax.precision > reserved)
		return (syntax.precision + 2);
	return (reserved + 2);
}
