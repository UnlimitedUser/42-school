/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapbubble_down.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:04:47 by dsclearo          #+#    #+#             */
/*   Updated: 2017/03/22 20:04:48 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_heapbubble_down(int heap[], int n, int index)
{
	int		minindex;
	int		child;
	int		i;

	child = ft_heapfirstchild(heap, n, index);
	minindex = index;
	i = -1;
	while (++i < 2)
		if (i + child < n && heap[i + child] < heap[minindex])
			minindex = i + child;
	if (minindex != index)
	{
		ft_heapswap(heap, n, minindex, index);
		ft_heapbubble_down(heap, n, minindex);
	}
}
