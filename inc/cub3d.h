/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:20:20 by ysalmi            #+#    #+#             */
/*   Updated: 2023/06/19 10:09:15 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <float.h>
# include "libft.h"
# include "get_next_line.h"

# define TITLE "Cub3D"
# define WIDTH 1680
# define HEIGHT 1080


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
	K_R = 15,
	K_W = 13,
	K_S = 1,
	K_A = 0,
	K_D = 2
};

enum e_side
{
	TOP,
	BOTTOM,
	RIGHT,
	LEFT
};

/**************************************/
/***** 			Types		***********/
/**************************************/

typedef struct s_canvas	t_canvas;
typedef struct s_vect	t_vect;
typedef struct s_vect_i	t_vect_i;
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

struct s_vect_i
{
	int	x;
	int	y;
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
	int			w;
	int			h;
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
	t_canvas	view;
	t_canvas	minimap;
	t_camera	cam;
	t_house		house;
};

typedef struct s_hit
{
	int		done;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_dist;
	double	wall_pos;

	t_vect	dist;
}	t_hit;


/**************************************/
/***** 			Prototypes		*******/
/**************************************/

int	is_map_enclosed(char **map);



t_data	*init(void);
void	destroy(t_data *d);

int		init_minimap(t_data *d);
void	draw_minimap(t_data *d);
void	render_scene(t_data *d);

int		keydown_handler(int	key, t_data *d);

t_hit	raycaster(t_data *d, t_vect pos, t_vect ray);


int		init_canvas(t_data *data, t_canvas *c);
void	paint_pxl(t_canvas *c, int x, int y, int color);
int		get_pxl_color(t_canvas *c, int x, int y);
void	paint_canvas(t_canvas *c, int color);

void	draw_line(t_canvas *c, t_vect_i s, t_vect_i e, int color);
void	draw_line_minimap(t_data *d, t_vect start, t_vect end, int color);


/**************************************/
/***** 			Debug utils		*******/
/**************************************/

void	print_vect(t_vect v, char *name);
void	print_vect_i(t_vect_i v, char *name);

#endif
