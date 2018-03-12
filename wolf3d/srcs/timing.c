/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 14:02:11 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/22 14:02:13 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	timing(t_event *event)
{
	double	frame_time;

	event->old_time = event->time;
	event->time = clock();
	frame_time = (event->time - event->old_time) / CLOCKS_PER_SEC;
	ft_printf("Fps = %d\n", (int)(1.0 / frame_time));
	if (event->fast)
	{
		event->move_speed = frame_time * FAST_MOVE_OFFSET;
		event->rot_speed = frame_time * FAST_ROT_OFFSET;
	}
	else
	{
		event->move_speed = frame_time * MOVE_OFFSET;
		event->rot_speed = frame_time * ROT_OFFSET;
	}
}
