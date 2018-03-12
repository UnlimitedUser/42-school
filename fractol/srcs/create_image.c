/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:14:16 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/15 20:14:17 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	create_image(t_event *event)
{
	event->image.image = mlx_new_image(event->mlx, WIN_WIDTH, WIN_HEIGHT);
	event->image.data_address = mlx_get_data_addr(event->image.image,
		&event->image.bits_per_pixel, &event->image.size_line,
			&event->image.endian);
}
