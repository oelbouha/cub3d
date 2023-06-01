/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:53:42 by ysalmi            #+#    #+#             */
/*   Updated: 2023/01/28 12:04:47 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(const char *s, va_list args)
{
	int	count;
	int	cursor;

	if (!*s)
		return (0);
	count = 0;
	count += ft_print_const_str(s);
	cursor = count;
	count += ft_print_variable(&s[cursor], args, &cursor);
	count += ft_print_str(&s[cursor], args);
	return (count);
}
