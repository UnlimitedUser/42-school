/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:36:34 by dsclearo          #+#    #+#             */
/*   Updated: 2017/03/22 13:36:35 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_heapinsert(int heap[], int *n, int num)
{
	(*n)++;
	heap[*n] = num;
	ft_heapbubble_up(heap, *n, *n);
}