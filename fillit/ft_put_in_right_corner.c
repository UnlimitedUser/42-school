/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_in_right_corner.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:57:36 by dsclearo          #+#    #+#             */
/*   Updated: 2016/11/21 14:58:31 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_minus(int i, int a, t_vector (**vectors)[27][4])
{
	if (a)
	{
		(**vectors)[i][0].x--;
		(**vectors)[i][1].x--;
		(**vectors)[i][2].x--;
		(**vectors)[i][3].x--;
	}
	else
	{
		(**vectors)[i][0].y--;
		(**vectors)[i][1].y--;
		(**vectors)[i][2].y--;
		(**vectors)[i][3].y--;
	}
}

int		ft_put_in_right_corner(t_vector (*vectors)[27][4])
{
	int		i;

	i = 0;
	while ((*vectors)[i][0].x != -1)
	{
		while ((*vectors)[i][0].x - 1 >= 0 && (*vectors)[i][1].x - 1 >= 0 &&
				(*vectors)[i][2].x - 1 >= 0 && (*vectors)[i][3].x - 1 >= 0)
			ft_minus(i, 1, &vectors);
		i++;
	}
	i = 0;
	while ((*vectors)[i][0].x != -1)
	{
		while ((*vectors)[i][0].y - 1 >= 0 && (*vectors)[i][1].y - 1 >= 0 &&
				(*vectors)[i][2].y - 1 >= 0 && (*vectors)[i][3].y - 1 >= 0)
			ft_minus(i, 0, &vectors);
		i++;
	}
	return (i - 1);
}
