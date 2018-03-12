/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:58:16 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/18 13:58:18 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_colors(t_event *event, int dir)
{
	if (dir == 1)
		event->offset += 1000;
	else if (dir == -1)
		event->offset -= 1000;
	reload_image(event, 1);
}
