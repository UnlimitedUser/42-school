/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:01:51 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/05 19:30:43 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	turn_around_z(t_line *line, double alpha, t_point point)
{
	int		c;

	c = -1;
	while (line)
	{
		while (++c < line->length)
		{
			line->points[c].y -= point.y;
			line->points[c].x -= point.x;
			line->points[c].x = (line->points[c].x * cos(alpha) -
					line->points[c].y * sin(alpha));
			line->points[c].y = (line->points[c].x * sin(alpha) +
					line->points[c].y * cos(alpha));
			line->points[c].y += point.y;
			line->points[c].x += point.x;
		}
		c = -1;
		line = line->next_line;
	}
}

void	turn_around_y(t_line *line, double alpha, t_point point)
{
	int	c;

	c = -1;
	while (line)
	{
		while (++c < line->length)
		{
			line->points[c].x -= point.x;
			line->points[c].x = (line->points[c].x * cos(alpha) +
					line->points[c].z * sin(alpha));
			line->points[c].z = (line->points[c].x * -sin(alpha) +
					line->points[c].z * cos(alpha));
			line->points[c].x += point.x;
		}
		c = -1;
		line = line->next_line;
	}
}

void	turn_around_x(t_line *line, double alpha, t_point point)
{
	int	c;

	c = -1;
	while (line)
	{
		while (++c < line->length)
		{
			line->points[c].y -= point.y;
			line->points[c].y = ((line->points[c].y) * cos(alpha) -
					(line->points[c].z) * sin(alpha));
			line->points[c].z = ((line->points[c].y) * sin(alpha) +
					(line->points[c].z) * cos(alpha));
			line->points[c].y += point.y;
		}
		c = -1;
		line = line->next_line;
	}
}
