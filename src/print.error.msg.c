/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.error.msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:36:12 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/21 09:04:04 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error_msg(char *msg)
{
	ft_putstr_fd("cub3d: error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}
