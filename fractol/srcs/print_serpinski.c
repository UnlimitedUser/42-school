/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_serpinski.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:20:36 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/19 14:20:37 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	serpinski_itter(t_event *event, t_point p, int *iteration)
{
	t_complex	complex;

	complex.real = (p.x - WIN_WIDTH / 2) / (0.5 * event->scale * WIN_WIDTH) +
				event->zoom_offset.x;
	complex.imag = (p.y - WIN_HEIGHT / 2) / (0.5 * event->scale * WIN_HEIGHT) +
				event->zoom_offset.y;
	complex.real = ABS(complex.real);
	complex.imag = ABS(complex.imag);
	*iteration = 0;
	while ((complex.imag > 0 || complex.real > 0) && *iteration < MAXIMUM)
	{
		if ((int)complex.real % 3 == 1 && (int)complex.imag % 3 == 1)
		{
			put_pixel_to_image(event, p.y, p.x, event->pallete[*iteration]);
			return ;
		}
		complex.real /= 3;
		complex.imag /= 3;
		(*iteration)++;
	}
	put_pixel_to_image(event, p.y, p.x, 0x000000);
}

void	print_serpinski(t_event *event)
{
	t_point		p;
	int			iteration;

	p.y = -1;
	while (++p.y < WIN_HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIN_WIDTH)
			serpinski_itter(event, p, &iteration);
	}
}
