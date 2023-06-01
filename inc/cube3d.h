/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:20:20 by ysalmi            #+#    #+#             */
/*   Updated: 2023/05/31 19:47:16 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"

# define WIDTH 1080
# define HEIGHT 760


/**************************************/
/***** 			Enums		***********/
/**************************************/

enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_RIGHTCLICK = 1,
	ON_LEFTCLICK = 2,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_keys
{
	K_ESC = 53,
	K_UP = 126,
	K_DOWN = 125,
	K_LEFT = 123,
	K_RIGHT = 124,
	K_SPACE = 49,
	K_R = 15
};

/**************************************/
/***** 			Types		***********/
/**************************************/

typedef struct s_canvas	t_canvas;
typedef struct s_data	t_data;

struct s_canvas
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
};

struct s_data
{
	void	*mlx;
	void	*win;
};




int		init_canvas(t_data *data, t_canvas *c);
void	paint_pxl(t_canvas *c, int x, int y, int color);
int		get_pxl_color(t_canvas *c, int x, int y);
void	paint_canvas(t_canvas *c, int color);

#endif
