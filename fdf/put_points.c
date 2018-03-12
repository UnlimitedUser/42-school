/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:50:26 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/05 18:58:12 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_points(t_line *line, void *mlx, void *window)
{
	int	x;

	while (line)
	{
		x = -1;
		while (++x < line->length)
		{
			if (x + 1 < line->length)
				print_line(mlx, window, line->points[x], line->points[x + 1]);
			if (line->next_line)
				print_line(mlx, window, line->points[x],
						line->next_line->points[x]);
		}
		line = line->next_line;
	}
}
