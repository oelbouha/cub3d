/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:37:45 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/12 10:33:07 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_vect(t_vect v, char *name)
{
	printf("%s:\n{%010.6f\t%010.6f}\n\n", name, v.x, v.y);
}

void	print_vect_i(t_vect_i v, char *name)
{
	printf("%s:\n{%010d\t%010d}\n\n", name, v.x, v.y);
}
