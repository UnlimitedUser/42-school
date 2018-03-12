/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:16:16 by dsclearo          #+#    #+#             */
/*   Updated: 2017/03/22 19:16:17 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_heapswap(int heap[], int n, int a, int b)
{
	int		tmp;

	(void)n;
	tmp = heap[a];
	heap[a] = heap[b];
	heap[b] = tmp;
}
