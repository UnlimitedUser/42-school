/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:05:17 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/24 19:05:19 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	put_in_buff(t_event *event, int x, int vals[], int side)
{
	int		y;
	int		d;
	int		tex_y;
	int		color;

	y = vals[1] - 1;
	while (++y < vals[2])
	{
		d = y * 256 - WIN_HEIGHT * 128 + vals[0] * 128;
		tex_y = ((d * TEX_HEIGHT) / vals[0]) / 256;
		color = event->textures[event->tex_num][TEX_HEIGHT *
			tex_y + vals[3]];
		if (side == 0)
			color = (color >> 1) & 8355711;
		put_pixel_to_image(event, y, x, color);
	}
}
