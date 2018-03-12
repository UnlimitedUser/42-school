/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:45:22 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/22 16:45:22 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	turn_left(t_event *event)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = event->direction.x;
	event->direction.x = event->direction.x * cos(event->rot_speed) -
		event->direction.y * sin(event->rot_speed);
	event->direction.y = old_dir_x * sin(event->rot_speed) +
		event->direction.y * cos(event->rot_speed);
	old_plane_x = event->plane.x;
	event->plane.x = event->plane.x * cos(event->rot_speed) - event->plane.y *
		sin(event->rot_speed);
	event->plane.y = old_plane_x * sin(event->rot_speed) +
		event->plane.y * cos(event->rot_speed);
}

void	turn_right(t_event *event)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = event->direction.x;
	event->direction.x = event->direction.x * cos(-event->rot_speed) -
		event->direction.y * sin(-event->rot_speed);
	event->direction.y = old_dir_x * sin(-event->rot_speed) +
		event->direction.y * cos(-event->rot_speed);
	old_plane_x = event->plane.x;
	event->plane.x = event->plane.x * cos(-event->rot_speed) - event->plane.y *
		sin(-event->rot_speed);
	event->plane.y = old_plane_x * sin(-event->rot_speed) +
		event->plane.y * cos(-event->rot_speed);
}
