/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 22:25:12 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/20 22:25:13 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	put_pixel_to_image(t_event *event, double x, double y, int color)
{
	size_t	a;
	int		c;

	a = mlx_get_color_value(event->mlx, color);
	c = (int)(x * event->image.size_line + y * 4);
	event->image.data_address[c] = 0;
	event->image.data_address[c + 1] = (char)((a >> 16) & 0xFF);
	event->image.data_address[c + 2] = (char)((a >> 8) & 0xFF);
	event->image.data_address[c + 3] = (char)(a & 0xFF);
}
