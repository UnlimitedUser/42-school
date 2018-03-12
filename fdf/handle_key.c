/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:45:10 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/05 19:07:40 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_qweasdzx(int k, void *p)
{
	if (k == KEY_S)
		turn_around_x((*(t_event *)p).line, -OFFSET, (*(t_event *)p).center);
	else if (k == KEY_W)
		turn_around_x((*(t_event *)p).line, OFFSET, (*(t_event *)p).center);
	else if (k == KEY_D)
		turn_around_y((*(t_event *)p).line, OFFSET, (*(t_event *)p).center);
	else if (k == KEY_A)
		turn_around_y((*(t_event *)p).line, -OFFSET, (*(t_event *)p).center);
	else if (k == KEY_Q)
		turn_around_z((*(t_event *)p).line, OFFSET, (*(t_event *)p).center);
	else if (k == KEY_E)
		turn_around_z((*(t_event *)p).line, -OFFSET, (*(t_event *)p).center);
}

int		handle_key(int key, void *param)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window((*(t_event *)param).mlx, (*(t_event *)param).window);
		exit(0);
	}
	key_qweasdzx(key, param);
	if (key == KEY_UP)
		increase_offset((*(t_event *)param).line, 0, -3);
	else if (key == KEY_LEFT)
		increase_offset((*(t_event *)param).line, -3, 0);
	else if (key == KEY_DOWN)
		increase_offset((*(t_event *)param).line, 0, 3);
	else if (key == KEY_RIGHT)
		increase_offset((*(t_event *)param).line, 3, 0);
	else if (key == KEY_H)
		((*(t_event *)param).display_help) =
			((*(t_event *)param).display_help) ? 0 : 1;
	else if (key == KEY_Z)
		scale((*(t_event *)param).line, 1.1, (*(t_event *)param).center);
	else if (key == KEY_X)
		scale((*(t_event *)param).line, 0.9, (*(t_event *)param).center);
	redraw(((t_event *)param));
	return (1);
}
