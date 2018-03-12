/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pallete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:45:12 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/15 20:45:21 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_pallete(t_event *event, int offset)
{
	int		i;
	int		a;

	i = offset;
	a = 0;
	while (a < MAXIMUM)
	{
		event->pallete[a] = i;
		i += offset;
		a++;
	}
}
