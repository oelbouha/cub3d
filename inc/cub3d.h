/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:20:20 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/07 21:52:37 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"

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
typedef struct s_vect	t_vect;
typedef struct s_camera	t_camera;
typedef struct s_house	t_house;
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

struct s_vect
{
	double	x;
	double	y;
};

struct s_camera
{
	t_vect	pos;
	t_vect	dir;
	t_vect	plane;
};

struct	s_house
{
	char		**map;
	t_canvas	north;
	t_canvas	south;
	t_canvas	west;
	t_canvas	east;
	int			ceiling;
	int			floor;
};

struct s_data
{
	void		*mlx;
	void		*win;
	t_camera	cam;
	t_house		house;
};


/**************************************/
/***** 			Prototypes		*******/
/**************************************/


int		init_canvas(t_data *data, t_canvas *c);
void	paint_pxl(t_canvas *c, int x, int y, int color);
int		get_pxl_color(t_canvas *c, int x, int y);
void	paint_canvas(t_canvas *c, int color);

#endif
