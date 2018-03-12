/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 13:35:23 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/22 13:35:24 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	reload_image(t_event *event)
{
	mlx_clear_window(event->mlx, event->win);
	ray_casting(event);
	mlx_put_image_to_window(event->mlx,
		event->win, event->image.image, 0, 0);
}
