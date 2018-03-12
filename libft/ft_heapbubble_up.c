/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapbubble_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:04:52 by dsclearo          #+#    #+#             */
/*   Updated: 2017/03/22 20:04:54 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_heapbubble_up(int heap[], int size, int n)
{
	if (n == 0)
		return;
	if (heap[ft_heapparent(heap, size, n)] > heap[n])
	{
		ft_heapswap(heap, n, ft_heapparent(heap, size, n), n);
		ft_heapbubble_up(heap, size, ft_heapparent(heap, size, n));
	}
}
