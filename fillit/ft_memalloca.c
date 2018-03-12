/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloca.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:09:36 by dsclearo          #+#    #+#             */
/*   Updated: 2016/11/21 14:56:41 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	**ft_memalloca(int row)
{
	void	**map;
	int		a;

	a = -1;
	if (!(map = (void **)ft_memalloc((size_t)(sizeof(void *) * row))))
		return (NULL);
	while (++a < row)
		if (!(map[a] = ft_memalloc((size_t)row)))
			return (NULL);
	return (map);
}
