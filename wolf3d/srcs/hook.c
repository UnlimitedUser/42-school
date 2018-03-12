/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 13:55:41 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/22 13:55:42 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		expose_hook(t_event *event)
{
	mlx_put_image_to_window(event->mlx, event->win, event->image.image, 0, 0);
	return (0);
}

int		loop_hook(t_event *event)
{
	if (event->turn_left)
		turn_left(event);
	if (event->turn_right)
		turn_right(event);
	if (event->go_up)
		move_up(event);
	if (event->go_down)
		move_down(event);
	if (event->go_down || event->go_up ||
			event->turn_right || event->turn_left)
		reload_image(event);
	return (0);
}
