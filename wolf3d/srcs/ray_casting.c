/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 22:33:54 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/20 22:33:55 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init(t_event *event, double *camera_x, int x)
{
	*camera_x = 2 * x / (double)WIN_WIDTH - 1;
	event->ray_pos = (t_point){event->player.x, event->player.y};
	event->ray_dir = (t_point){event->direction.x + event->plane.x *
		*camera_x, event->direction.y + event->plane.y * *camera_x};
	event->map = (t_point){(int)event->ray_pos.x, (int)event->ray_pos.y};
	event->delta_dist = (t_point){sqrt(1 + pow(event->ray_dir.y, 2) /
		pow(event->ray_dir.x, 2)), sqrt(1 + pow(event->ray_dir.x, 2) /
			pow(event->ray_dir.y, 2))};
}

void	directions(t_event *event)
{
	if (event->ray_dir.x < 0)
	{
		event->step.x = -1;
		event->side_dist.x = (event->ray_pos.x - event->map.x) *
				event->delta_dist.x;
	}
	else
	{
		event->step.x = 1;
		event->side_dist.x = (event->map.x + 1.0 - event->ray_pos.x) *
				event->delta_dist.x;
	}
	if (event->ray_dir.y < 0)
	{
		event->step.y = -1;
		event->side_dist.y = (event->ray_pos.y - event->map.y) *
				event->delta_dist.y;
	}
	else
	{
		event->step.y = 1;
		event->side_dist.y = (event->map.y + 1.0 - event->ray_pos.y) *
				event->delta_dist.y;
	}
}

void	go_until_hit(t_event *event, int *side)
{
	int		hit;

	hit = 0;
	while (!hit)
	{
		if (event->side_dist.x < event->side_dist.y)
		{
			event->side_dist.x += event->delta_dist.x;
			event->map.x += event->step.x;
			*side = 0;
		}
		else
		{
			event->side_dist.y += event->delta_dist.y;
			event->map.y += event->step.y;
			*side = 1;
		}
		if (event->world_map[(int)event->map.x][(int)event->map.y] > 0)
			hit = 1;
	}
}

#define A if (vals[1] < 0)vals[1] = 0;
#define B if (vals[2] >= WIN_HEIGHT)vals[2] = WIN_HEIGHT - 1;
#define D event->wall_x
#define C D -= floor(D);vals[3] = (int)(D * (double)TEX_WIDTH);

int		draw_vertical(t_event *event, int side, double *perp_wall_dist,
		int x)
{
	int		vals[4];

	if (side == 0)
		*perp_wall_dist = (event->map.x - event->ray_pos.x +
				(1 - event->step.x) / 2) / event->ray_dir.x;
	else
		*perp_wall_dist = (event->map.y - event->ray_pos.y +
				(1 - event->step.y) / 2) / event->ray_dir.y;
	vals[0] = (int)(WIN_HEIGHT / *perp_wall_dist);
	vals[1] = -vals[0] / 2 + WIN_HEIGHT / 2;
	A
	vals[2] = vals[0] / 2 + WIN_HEIGHT / 2;
	B
	event->tex_num = event->world_map[(int)event->map.x]
		[(int)event->map.y] - 1;
	if (side == 0)
		event->wall_x = event->ray_pos.y + *perp_wall_dist * event->ray_dir.y;
	else
		event->wall_x = event->ray_pos.x + *perp_wall_dist * event->ray_dir.x;
	C
	if(side == 0 && event->ray_dir.x > 0)
		vals[3] = TEX_WIDTH - vals[3] - 1;
	if(side == 1 && event->ray_dir.y < 0)
		vals[3] = TEX_WIDTH - vals[3] - 1;
	put_in_buff(event, x, vals, side);
	return (vals[2]);
}

void	ray_casting(t_event *event)
{
	double	camera_x;
	int		side[2];
	double	perp_wall_dist;

	side[1] = -1;
	perp_wall_dist = 0;
	while (++side[1] < WIN_WIDTH)
	{
		init(event, &camera_x, side[1]);
		directions(event);
		go_until_hit(event, &side[0]);
		floor_casting(event, side, draw_vertical(event,
			side[0], &perp_wall_dist, side[1]), perp_wall_dist);
	}
	timing(event);
}
