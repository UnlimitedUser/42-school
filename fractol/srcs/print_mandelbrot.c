/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:23:18 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/15 16:23:20 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot_itter(t_event *event, t_point p, int *iteration)
{
	t_complex	complex;
	t_point		a;
	double		x_new;

	complex.real = (p.x - WIN_WIDTH / 2) / (0.5 * event->scale * WIN_WIDTH) +
			event->zoom_offset.x;
	complex.imag = (p.y - WIN_HEIGHT / 2) / (0.5 * event->scale * WIN_HEIGHT) +
			event->zoom_offset.y;
	a.x = 0;
	a.y = 0;
	*iteration = 0;
	while (a.x * a.x + a.y * a.y <= 4 && *iteration < MAXIMUM)
	{
		x_new = a.y * a.y - a.x * a.x + complex.real;
		a.x = 2 * a.y * a.x + complex.imag;
		a.y = x_new;
		(*iteration)++;
	}
	if (*iteration < MAXIMUM)
		put_pixel_to_image(event, p.y, p.x, event->pallete[*iteration]);
	else
		put_pixel_to_image(event, p.y, p.x, 0x000000);
}

void	print_mandelbrot(t_event *event)
{
	t_point		p;
	int			iteration;

	p.y = -1;
	while (++p.y < WIN_HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIN_WIDTH)
			mandelbrot_itter(event, p, &iteration);
	}
}
