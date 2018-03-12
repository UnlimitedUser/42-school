/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:57:59 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/27 18:17:05 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_motion(int x, int y, t_event *event)
{
	if (!event->mouse_motion)
		return (0);
	event->mouse.real = (double)x / (double)WIN_WIDTH * 4 - 2;
	event->mouse.imag = (double)y / (double)WIN_HEIGHT * 4 - 2;
	reload_image(event, 0);
	return (0);
}

void	triger_mouse_motion(t_event *event)
{
	event->mouse_motion = !event->mouse_motion;
}
