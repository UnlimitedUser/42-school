/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_2d_to_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:06:06 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/20 16:54:15 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	from_2d_to_3d(t_line *line)
{
	int		x;

	while (line)
	{
		x = -1;
		while (++x < line->length)
		{
			line->points[x].u = (int)(line->points[x].x);
			line->points[x].v = (int)(line->points[x].y);
		}
		line = line->next_line;
	}
}
