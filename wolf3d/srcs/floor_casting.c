/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:15:02 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/27 15:20:15 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	loop(double dists[], t_point floor[], t_event *event, int side[])
{
	int		y;

	y = (int)dists[4];
	while (++y < WIN_HEIGHT)
	{
		dists[2] = WIN_HEIGHT / (2.0 * y - WIN_HEIGHT);
		dists[3] = (dists[2] - dists[1]) / (dists[0] - dists[1]);
		floor[1] = (t_point) {dists[3] * floor[0].x + (1.0 - dists[3]) *
event->player.x, dists[3] * floor[0].y + (1.0 - dists[3]) * event->player.y};
		floor[2] = (t_point) {(int)(floor[1].x * TEX_WIDTH) % TEX_WIDTH,
			(int)(floor[1].y * TEX_HEIGHT) % TEX_HEIGHT};
		put_pixel_to_image(event, y, side[1], (event->textures[3][(int)
			(TEX_WIDTH * floor[2].y + floor[2].x)] >> 1) & 8355711);
		put_pixel_to_image(event, WIN_HEIGHT - y, side[1],
			event->textures[2][(int)(TEX_WIDTH * floor[2].y + floor[2].x)]);
	}
}

void	floor_casting(t_event *event, int side[], int draw_end,
		double perp_wall_dist)
{
	t_point	floor[3];
	double	dists[5];

	if (side[0] == 0 && event->ray_dir.x > 0)
		floor[0] = (t_point){event->map.x, event->map.y + event->wall_x};
	else if (side[0] == 0 && event->ray_dir.x < 0)
		floor[0] = (t_point){event->map.x + 1.0, event->map.y + event->wall_x};
	else if (side[0] == 1 && event->ray_dir.y > 0)
		floor[0] = (t_point){event->map.x + event->wall_x, event->map.y};
	else
		floor[0] = (t_point){event->map.x + event->wall_x, event->map.y + 1.0};
	dists[0] = perp_wall_dist;
	dists[1] = 0.0;
	if (draw_end < 0)
		draw_end = WIN_HEIGHT;
	dists[4] = draw_end;
	loop(dists, floor, event, side);
}
