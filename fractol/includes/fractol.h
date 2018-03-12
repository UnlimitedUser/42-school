/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:50:51 by dsclearo          #+#    #+#             */
/*   Updated: 2017/05/02 18:17:32 by dansclear        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <math.h>
# include "mlx.h"

# define WIN_WIDTH 700
# define WIN_HEIGHT 700
# define MAXIMUM 100
# define NAME "Fract'ol"
# define PTR_MOTION_MASK (1L << 6)
# define MOTION_NOTIFY 6
# define MOUSE_ZOOM_IN 5
# define MOUSE_ZOOM_OUT 4
# define KEY_ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14

typedef enum		e_type
{
	mandelbrot,
	julia,
	imaginary,
	julia2,
	julia3,
	julia4,
	b_ship,
	dragon,
	serpinski
}					t_type;

typedef struct		s_complex
{
	double			real;
	double			imag;
}					t_complex;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_image
{
	void			*image;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*data_address;
}					t_image;

typedef struct		s_event
{
	void			(*function)(struct s_event *event);
	void			*mlx;
	void			*window;
	int				pallete[MAXIMUM];
	int				offset;
	double			scale;
	int				mouse_motion;
	t_point			zoom_offset;
	t_complex		mouse;
	t_image			image;
	t_type			type;
}					t_event;

void				show_usage_and_exit();
void				print_mandelbrot(t_event *event);
void				print_julia(t_event *event);
void				print_julia2(t_event *event);
void				print_julia3(t_event *event);
void				print_julia4(t_event *event);
void				print_b_ship(t_event *event);
void				print_imaginary(t_event *event);
void				print_serpinski(t_event *event);
void				print_dragon(t_event *event);
void				create_image(t_event *event);
void				put_pixel_to_image(t_event *event, double x,
									double y, int color);
void				init_pallete(t_event *event, int offset);
int					mouse_hook(int button, int x, int y, t_event *param);
void				reload_image(t_event *event, int a);
int					expose_hook(t_event *event);
int					mouse_motion(int x, int y, t_event *event);
void				triger_mouse_motion(t_event *event);
void				change_colors(t_event *event, int dir);
int					key_hook(int key, t_event *event);

#endif
