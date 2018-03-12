/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_offset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:31:07 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/05 19:32:32 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	increase_offset(t_line *line, double offx, double offy)
{
	int	x;

	while (line)
	{
		x = -1;
		while (++x < line->length)
		{
			line->points[x].x += offx;
			line->points[x].y += offy;
		}
		line = line->next_line;
	}
}
