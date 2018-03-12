/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:41:41 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/24 16:41:43 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	move_up(t_event *event)
{
	if (!event->world_map[(int)(event->player.x + event->direction.x *
			event->move_speed)][(int)event->player.y])
		event->player.x += event->direction.x * event->move_speed;
	if (!event->world_map[(int)event->player.x][(int)(event->player.y +
			event->direction.y * event->move_speed)])
		event->player.y += event->direction.y * event->move_speed;
}

void	move_down(t_event *event)
{
	if (!event->world_map[(int)(event->player.x - event->direction.x *
			event->move_speed)][(int)event->player.y])
		event->player.x -= event->direction.x * event->move_speed;
	if (!event->world_map[(int)event->player.x][(int)(event->player.y -
			event->direction.y * event->move_speed)])
		event->player.y -= event->direction.y * event->move_speed;
}
