/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:27:57 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/24 17:27:58 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

#define A (x != y && x != TEX_WIDTH - y);
#define B colors[2] + 65536 * colors[2];
#define C 65536 * colors[2];
#define D (x % 16 && y % 16);
#define E 65536 * 128;
#define F colors[0] + 65536 * colors[0];

void	generate_textures(t_event *event)
{
	int		x;
	int		y;
	int		colors[3];

	x = -1;
	while (++x < TEX_HEIGHT)
	{
		y = -1;
		while (++y < TEX_HEIGHT)
		{
			colors[0] = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
			colors[1] = y * 256 / TEX_HEIGHT;
			colors[2] = y * 128 / TEX_HEIGHT + x * 128 / TEX_WIDTH;
			event->textures[0][TEX_WIDTH * y + x] = 65536 * 254 * A
			event->textures[1][TEX_WIDTH * y + x] = colors[2] + 256 * B
			event->textures[2][TEX_WIDTH * y + x] = 256 * colors[2] + C
			event->textures[3][TEX_WIDTH * y + x] = 256 * colors[0];
			event->textures[4][TEX_WIDTH * y + x] = 65536 * 192 * D
			event->textures[5][TEX_WIDTH * y + x] = 65536 * colors[1];
			event->textures[6][TEX_WIDTH * y + x] = 128 + 256 * 128 + E
			event->textures[7][TEX_WIDTH * y + x] = colors[0] + 256 * F
		}
	}
}
