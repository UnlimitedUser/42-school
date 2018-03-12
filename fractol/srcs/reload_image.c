/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 22:23:04 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/20 17:08:46 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	reload_image(t_event *event, int a)
{
	create_image(event);
	if (a)
		init_pallete(event, event->offset);
	event->function(event);
	mlx_put_image_to_window(event->mlx, event->window,
			event->image.image, 0, 0);
	mlx_destroy_image(event->mlx, event->image.image);
}
