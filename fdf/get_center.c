/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 20:20:15 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/20 16:54:54 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_line	*get_last_line(t_line *line)
{
	while (line->next_line)
		line = line->next_line;
	return (line);
}

void			get_center(t_event *event)
{
	t_line	*last_line;

	last_line = get_last_line(event->line);
	event->center.x = (last_line->points[event->line->length - 1].x +
			event->line->points[0].x) / 2;
	event->center.y = (last_line->points[event->line->length - 1].y +
			event->line->points[0].y) / 2;
}
