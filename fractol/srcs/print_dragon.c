/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dragon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:07:05 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/20 13:13:21 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	dragon_itter(t_event *event, t_point *p, t_complex complex,
		int *iteration)
{
	t_point		a;
	double		x_new;

	a.x = ((*p).x - WIN_WIDTH / 2) / (0.5 * event->scale * WIN_WIDTH) +
		event->zoom_offset.x;
	a.y = ((*p).y - WIN_HEIGHT / 2) / (0.5 * event->scale * WIN_HEIGHT) +
		event->zoom_offset.y;
	*iteration = 0;
	while (a.x * a.x + a.y * a.y <= 4 && *iteration < MAXIMUM)
	{
		x_new = a.x;
		a.x = a.x * a.x * a.x - (3 * a.x * a.y * a.y) + complex.real;
		a.y = (3 * x_new * x_new * a.y) + complex.imag;
		(*iteration)++;
	}
	if (*iteration < MAXIMUM)
		put_pixel_to_image(event, (*p).y, (*p).x, event->pallete[*iteration]);
	else
		put_pixel_to_image(event, (*p).y, (*p).x, 0x000000);
}

void	print_dragon(t_event *event)
{
	t_point		p;
	t_complex	complex;
	int			iteration;

	p.y = -1;
	complex.imag = event->mouse.imag;
	complex.real = event->mouse.real;
	while (++p.y < WIN_HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIN_WIDTH)
			dragon_itter(event, &p, complex, &iteration);
	}
}
