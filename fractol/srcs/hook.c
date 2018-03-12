/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 22:48:26 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/20 13:16:14 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		expose_hook(t_event *event)
{
	mlx_put_image_to_window(event->mlx, event->window,
			event->image.image, 0, 0);
	return (0);
}

int		key_hook(int key, t_event *event)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(event->mlx, event->window);
		exit(0);
	}
	else if (key == KEY_Q)
		change_colors(event, 1);
	else if (key == KEY_W)
		change_colors(event, -1);
	else if (key == KEY_E)
		triger_mouse_motion(event);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_event *event)
{
	if (button == MOUSE_ZOOM_IN)
		event->scale /= 1.1;
	else if (button == MOUSE_ZOOM_OUT)
		event->scale *= 1.1;
	event->zoom_offset.x += (((double)x - WIN_HEIGHT / 2) /
			WIN_WIDTH / 2) / event->scale;
	event->zoom_offset.y += (((double)y - WIN_WIDTH / 2) /
			WIN_HEIGHT / 2) / event->scale;
	reload_image(event, 0);
	return (0);
}
