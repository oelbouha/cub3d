/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:53:20 by ysalmi            #+#    #+#             */
/*   Updated: 2023/01/28 12:04:56 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pad_left(t_syntax syntax, int reserved)
{
	int		padding;
	char	fill;

	if (syntax.width && !ft_strchr(syntax.flags, '-'))
	{
		padding = syntax.width - reserved;
		fill = ' ';
		if (ft_strchr(syntax.flags, '0') && !(ft_strchr("diuxX", syntax.type)
				&& syntax.precision >= 0))
			fill += 16;
		if (padding++ > 0)
		{
			while (--padding)
				ft_putchar_fd(fill, 1);
			return (1);
		}
	}
	return (0);
}

int	ft_pad_right(t_syntax syntax, int reserved)
{
	int		padding;

	if (syntax.width && ft_strchr(syntax.flags, '-'))
	{
		padding = syntax.width - reserved;
		if (padding++ > 0)
		{
			while (--padding)
				ft_putchar_fd(' ', 1);
			return (1);
		}
	}
	return (0);
}
