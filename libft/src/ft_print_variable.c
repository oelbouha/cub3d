/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:12:09 by ysalmi            #+#    #+#             */
/*   Updated: 2023/01/28 12:04:42 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		init_syntax(t_syntax *syntax);
static t_syntax	extract_syntax(const char *s, t_syntax syntax);
static char		get_char(t_syntax stx, const char *s);

int	ft_print_variable(const char *s, va_list args, int *cursor)
{
	t_syntax	syntax;
	int			printed_length;

	if (!*s)
		return (0);
	init_syntax(&syntax);
	syntax = extract_syntax(s, syntax);
	printed_length = 0;
	if (syntax.type == '%' || syntax.type == 0)
		printed_length = print_char(syntax, get_char(syntax, s));
	else if (syntax.type == 'c')
		printed_length = print_char(syntax, va_arg(args, int));
	else if (syntax.type == 's')
		printed_length = print_str(syntax, va_arg(args, char *));
	else if (syntax.type == 'p')
		printed_length = print_pointer(syntax, va_arg(args, void *));
	else if (syntax.type == 'd' || syntax.type == 'i' || syntax.type == 'u')
		printed_length = print_number(syntax, va_arg(args, int));
	else if (syntax.type == 'x' || syntax.type == 'X')
		printed_length = print_hex(syntax, va_arg(args, int));
	*cursor += syntax.length;
	return (printed_length);
}

static t_syntax	extract_syntax(const char *s, t_syntax stx)
{
	int	i;

	i = 0;
	stx.length = 1;
	while (ft_strchr("-+ 0#", s[stx.length]))
	{
		if (!ft_strchr(stx.flags, s[stx.length]))
			stx.flags[i++] = s[stx.length];
		stx.length++;
	}
	if (ft_isdigit(s[stx.length]))
	{
		stx.width = ft_atoi(&s[stx.length]);
		stx.length += get_num_length(stx.width);
	}
	if (s[stx.length] == '.')
	{
		stx.precision = ft_atoi(&s[++stx.length]);
		stx.length += get_num_length(stx.precision) * ft_isdigit(s[stx.length]);
	}
	if (ft_strchr("cspdiuxX%", s[stx.length]))
		stx.type = s[stx.length++];
	return (stx);
}

static void	init_syntax(t_syntax *syntax)
{
	int	i;

	i = -1;
	while (++i < 6)
		syntax->flags[i] = 0;
	syntax->width = 0;
	syntax->precision = -1;
	syntax->type = 0;
	syntax->length = 0;
}

static char	get_char(t_syntax stx, const char *s)
{
	char	c;

	if (stx.type == '%')
		c = '%';
	else
		c = s[stx.length];
	return (c);
}
