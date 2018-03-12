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

#include "fdf.h"

void	print_line(void *mlx, void *window, t_point src, t_point dst)
{
	int	vals[6];

	vals[0] = abs(dst.u - src.u);
	vals[1] = abs(dst.v - src.v);
	vals[2] = src.u < dst.u ? 1 : -1;
	vals[3] = src.v < dst.v ? 1 : -1;
	vals[4] = (vals[0] > vals[1] ? vals[0] : -vals[1]) / 2;
	while (!(src.u == dst.u && src.v == dst.v))
	{
		mlx_pixel_put(mlx, window, src.u, src.v, dst.color);
		vals[5] = vals[4];
		if (vals[5] > -vals[0])
		{
			vals[4] -= vals[1];
			src.u += vals[2];
		}
		if (vals[5] < vals[1])
		{
			vals[4] += vals[0];
			src.v += vals[3];
		}
	}
}
