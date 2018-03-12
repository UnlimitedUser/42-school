/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:29:51 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/05 19:01:19 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_H 4
# define KEY_Z 6
# define KEY_X 7
# define COLOR_BRIGHT_GREEN 0x77fd04
# define COLOR_BRIGHT_GRAY 0x64371d
# define COLOR_DARK_BLUE 0x00004c
# define COLOR_BLUE 0x0000cc
# define COLOR_BRIGHT_BLUE 0x0080ff
# define COLOR_BRIGHT_BROWN 0x64420d
# define COLOR_DARK_BROWN 0x452209

# define OFFSET 0.1

typedef struct		s_point
{
	double			offx;
	double			offy;
	double			x;
	double			y;
	double			z;
	int				u;
	int				v;
	int				color;
}					t_point;

typedef struct		s_line
{
	t_point			*points;
	int				length;
	struct s_line	*next_line;
}					t_line;

typedef struct		s_event
{
	t_point			center;
	t_line			*line;
	void			*mlx;
	void			*window;
	int				lines;
	unsigned int	display_help : 1;
}					t_event;

void				put_points(t_line *points, void *mlx, void *window);
int					read_from_file(char *file, t_line **points,
		int *width, int *size);
void				print_line(void *mlx, void *window,
		t_point src, t_point dst);
void				increase_offset(t_line *line, double offx, double offy);
int					handle_key(int key, void *param);
int					redraw(t_event *env);
int					pick_color(int height);
void				display_help(t_event mlx);
void				from_2d_to_3d(t_line *line);
void				turn_around_z(t_line *line, double alpha, t_point point);
void				turn_around_y(t_line *line, double alpha, t_point point);
void				turn_around_x(t_line *line, double alpha, t_point point);
void				get_center(t_event *event);
void				scale(t_line *line, double alpha, t_point point);

#endif
