/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:28:18 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/06 16:10:45 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	print_line(t_event *event, t_point src, t_point dst, int color)
{
	int		vals[6];

	vals[0] = (int)fabs(dst.x - src.x);
	vals[1] = (int)fabs(dst.y - src.y);
	vals[2] = src.x < dst.x ? 1 : -1;
	vals[3] = src.y < dst.y ? 1 : -1;
	vals[4] = (vals[0] > vals[1] ? vals[0] : -vals[1]) / 2;
	while (!(src.x == dst.x && src.y == dst.y))
	{
		put_pixel_to_image(event, src.x, src.y, color);
		vals[5] = vals[4];
		if (vals[5] > -vals[0])
		{
			vals[4] -= vals[1];
			src.x += vals[2];
		}
		if (vals[5] < vals[1])
		{
			vals[4] += vals[0];
			src.y += vals[3];
		}
	}
}
