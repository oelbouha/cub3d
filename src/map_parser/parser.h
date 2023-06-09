/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:38:23 by oelbouha          #+#    #+#             */
/*   Updated: 2023/06/09 11:55:25 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include "cub3d.h"

t_house		parse_map(char *file, t_data data);
void		print_error_msg(char *msg);
int			destroy_north_img(t_data *data);
int			destroy_south_img(t_data *data);
int			destroy_west_img(t_data *data);
int			create_rgb(int r, int g, int b);
int			create_colors(char *line, t_house *house);
char		**get_rectangle_map(t_list *lst);

int			open_textures(char *line, t_house *house, t_data *data);
void		print_arr(char **arr);
void		print(t_list *lst);

#endif