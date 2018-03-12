/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:12:43 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/05 19:29:25 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_help(t_event mlx)
{
	mlx_string_put(mlx.mlx, mlx.window, 0, 0, 0x12FF54,
			"press up to move up");
	mlx_string_put(mlx.mlx, mlx.window, 0, 15, 0x12FF54,
			"press down to move");
	mlx_string_put(mlx.mlx, mlx.window, 0, 30, 0x12FF54,
			"press left to move left");
	mlx_string_put(mlx.mlx, mlx.window, 0, 45, 0x12FF54,
			"press right to move right");
	mlx_string_put(mlx.mlx, mlx.window, 0, 60, 0x12FF54,
			"press q, w, e, a, s, d for rotating");
	mlx_string_put(mlx.mlx, mlx.window, 0, 75, 0x12FF54,
			"press z, x for rotating");
	mlx_string_put(mlx.mlx, mlx.window, 0, 90, 0x12FF54,
			"press h for toggling this message");
}
