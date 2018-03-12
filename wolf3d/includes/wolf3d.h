/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:52:36 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/27 14:57:06 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <time.h>
# include <fcntl.h>
# include <stdio.h>

# define MAPWIDTH1 19
# define MAPHEIGHT1 8
# define MAPNAME1 "maps/simple.wolf"
# define MAPWIDTH2 8
# define MAPHEIGHT2 8
# define MAPNAME2 "maps/small.wolf"
# define MAPWIDTH3 71
# define MAPHEIGHT3 41
# define MAPNAME3 "maps/big.wolf"
# define MAPWIDTH4 23
# define MAPHEIGHT4 12
# define MAPNAME4 "maps/newmap.wolf"

# define MAP_WIDTH MAPWIDTH4
# define MAP_HEIGHT MAPHEIGHT4
# define FILE_NAME MAPNAME4

# define WIN_WIDTH 1000
# define WIN_HEIGHT 600
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define TITLE "wolf3d"
# define MOVE_OFFSET 4.0
# define ROT_OFFSET 3.8
# define FAST_MOVE_OFFSET 8.0
# define FAST_ROT_OFFSET 7.8
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_SHIFT 49
# define KEY_PRESS_MASK (1L << 0)
# define KEY_RELEASE_MASK (1L << 1)
# define BUTTON_PRESS_MASK (1L << 2)
# define BUTTON_RELEASE_MASK (1L << 3)
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define BUTTON_PRESS 4
# define BUTTON_RELEASE 5

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_image
{
	void		*image;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		*data_address;
}				t_image;

typedef struct	s_event
{
	void		*mlx;
	void		*win;
	t_image		image;
	t_point		player;
	t_point		direction;
	t_point		plane;
	t_point		ray_pos;
	t_point		ray_dir;
	t_point		map;
	t_point		side_dist;
	t_point		delta_dist;
	t_point		step;
	double		time;
	double		old_time;
	double		rot_speed;
	double		move_speed;
	double		wall_x;
	int			turn_left;
	int			turn_right;
	int			go_up;
	int			go_down;
	int			fast;
	int			tex_num;
	int			textures[8][TEX_HEIGHT * TEX_WIDTH];
	int			world_map[MAP_WIDTH][MAP_HEIGHT];
}				t_event;

void			put_pixel_to_image(t_event *event, double x,
							double y, int color);
void			ray_casting(t_event *event);
void			print_line(t_event *event, t_point src, t_point dst, int color);
void			exit_on_error(char *s);
void			print_r(t_event *event);
void			read_from_file(t_event *event);
void			reload_image(t_event *event);
int				expose_hook(t_event *event);
int				key_press(int key, t_event *event);
void			timing(t_event *event);
void			turn_left(t_event *event);
void			turn_right(t_event *event);
int				loop_hook(t_event *event);
void			move_up(t_event *event);
void			move_down(t_event *event);
int				key_release(int key, t_event *event);
void			generate_textures(t_event *event);
void			put_in_buff(t_event *event, int x, int vals[], int side);
void			floor_casting(t_event *event, int side[], int draw_end,
							double perp_wall_dist);
#endif
