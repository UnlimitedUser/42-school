/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:48:57 by dcaldare          #+#    #+#             */
/*   Updated: 2016/11/21 14:57:42 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_newmap(void)
{
	int		i;
	int		a;
	char	**map;

	a = -1;
	i = -1;
	if (!(map = (char **)ft_memalloca(g_size)))
		return (NULL);
	while (++i < g_size)
	{
		while (++a < g_size)
			map[i][a] = '.';
		a = -1;
	}
	return (map);
}
