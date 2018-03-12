/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 19:10:04 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/23 19:10:05 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		key_press(int key, t_event *event)
{
	if (key == KEY_UP)
		event->go_up = 1;
	else if (key == KEY_DOWN)
		event->go_down = 1;
	else if (key == KEY_LEFT)
		event->turn_left = 1;
	else if (key == KEY_RIGHT)
		event->turn_right = 1;
	else if (key == KEY_SHIFT)
		event->fast = 1;
	return (0);
}

int		key_release(int key, t_event *event)
{
	if (key == KEY_UP)
		event->go_up = 0;
	else if (key == KEY_DOWN)
		event->go_down = 0;
	else if (key == KEY_LEFT)
		event->turn_left = 0;
	else if (key == KEY_RIGHT)
		event->turn_right = 0;
	else if (key == KEY_SHIFT)
		event->fast = 0;
	return (0);
}
