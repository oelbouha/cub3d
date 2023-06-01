/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:08:58 by ysalmi            #+#    #+#             */
/*   Updated: 2023/01/28 12:03:51 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			put_number(unsigned int n);
static void			prepend(t_syntax stx, int neg, int before_padding);
static int			res(int r, int pre, int p);
static unsigned int	get_m(t_syntax stx, int n);

int	print_number(t_syntax stx, int n)
{
	int				reserved;
	int				precision;
	int				prepended;
	int				padded;
	unsigned int	m;

	m = get_m(stx, n);
	reserved = get_num_length(m) * (n != 0 || stx.precision != 0);
	precision = stx.precision;
	prepended = 0;
	if (stx.type != 'u')
		if (n < 0 || ft_strchr(stx.flags, ' ') || ft_strchr(stx.flags, '+'))
			prepended = 1;
	prepend(stx, n < 0, 1);
	padded = ft_pad_left(stx, res(reserved, prepended, stx.precision));
	prepend(stx, n < 0, 0);
	while (precision-- > reserved)
		ft_putchar_fd('0', 1);
	if (stx.precision != 0 || n)
		put_number(m);
	padded += ft_pad_right(stx, res(reserved, prepended, stx.precision));
	if (padded)
		return (stx.width);
	return (res(reserved, prepended, stx.precision));
}

static unsigned int	get_m(t_syntax stx, int n)
{
	if (stx.type == 'u')
		return ((unsigned int)n);
	return (n * (n > 0) - n * (n < 0));
}

static int	res(int r, int pre, int p)
{
	if (r > p)
		return (r + pre);
	return (p + pre);
}

static void	prepend(t_syntax stx, int neg, int before_padding)
{
	if ((before_padding && ft_strchr(stx.flags, '0')
			&& stx.precision < 0) || (!before_padding
			&& (!ft_strchr(stx.flags, '0') || stx.precision >= 0)))
	{
		if (stx.type != 'u' && neg)
			ft_putchar_fd('-', 1);
		else if (stx.type != 'u' && ft_strchr(stx.flags, '+'))
			ft_putchar_fd('+', 1);
		else if (stx.type != 'u' && ft_strchr(stx.flags, ' '))
			ft_putchar_fd(' ', 1);
	}
}

static void	put_number(unsigned int n)
{
	if (n / 10)
		put_number(n / 10);
	ft_putchar_fd(n % 10 + 48, 1);
}
