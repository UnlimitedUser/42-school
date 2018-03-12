/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapextract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:23:26 by dsclearo          #+#    #+#             */
/*   Updated: 2017/03/22 18:23:27 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_heapextract(int heap[], int *n)
{
	int		min;

	min = heap[0];
	heap[0] = heap[*n];
	ft_heapbubble_down(heap, *n, 0);
	(*n)--;
	return (min);
}
