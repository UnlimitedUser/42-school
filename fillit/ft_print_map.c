/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:36:54 by dsclearo          #+#    #+#             */
/*   Updated: 2016/11/21 14:58:12 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(char **map)
{
	int		a;
	int		i;

	i = -1;
	a = -1;
	if (!map)
		return ;
	while (++a < g_size)
	{
		while (++i < g_size)
			ft_putchar(map[a][i]);
		ft_putchar('\n');
		i = -1;
	}
}
