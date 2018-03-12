/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:31:50 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/05 19:27:48 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_line *line, double alpha, t_point point)
{
	int		c;

	c = -1;
	while (line)
	{
		while (++c < line->length)
		{
			line->points[c].x -= point.x;
			line->points[c].y -= point.y;
			line->points[c].x *= alpha;
			line->points[c].y *= alpha;
			line->points[c].x += point.x;
			line->points[c].y += point.y;
		}
		c = -1;
		line = line->next_line;
	}
}
