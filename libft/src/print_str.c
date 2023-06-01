/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:36:42 by ysalmi            #+#    #+#             */
/*   Updated: 2023/01/28 12:02:22 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_str(t_syntax syntax, char *s)
{
	char	*str;
	int		reserved;
	int		padded;
	int		i;

	str = s;
	if (!s)
		str = "(null)";
	reserved = ft_strlen(str);
	if (reserved > syntax.precision && syntax.precision > -1)
		reserved = syntax.precision;
	padded = ft_pad_left(syntax, reserved);
	i = 0;
	while (i < reserved)
		ft_putchar_fd(str[i++], 1);
	padded += ft_pad_right(syntax, reserved);
	if (padded)
		return (syntax.width);
	return (reserved);
}
