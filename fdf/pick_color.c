/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:48:24 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/05 19:32:02 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	pick_color(int height)
{
	if (height < 50 && height > -50)
		return (COLOR_BRIGHT_GRAY);
	else if (height > 200)
		return (COLOR_DARK_BROWN);
	else if (height > 150)
		return (COLOR_BRIGHT_BROWN);
	else if (height > 100)
		return (COLOR_BRIGHT_GREEN);
	else if (height > -200)
		return (COLOR_DARK_BLUE);
	else if (height > -150)
		return (COLOR_BLUE);
	else if (height > -100)
		return (COLOR_BRIGHT_BLUE);
	else
		return (0);
}
