/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:50:18 by ysalmi            #+#    #+#             */
/*   Updated: 2023/01/28 12:04:02 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(t_syntax syntax, char c)
{
	int		padded;

	padded = ft_pad_left(syntax, 1);
	ft_putchar_fd(c, 1);
	padded += ft_pad_right(syntax, 1);
	if (padded)
		return (syntax.width);
	return (1);
}
