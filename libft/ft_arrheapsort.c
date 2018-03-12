/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrheapsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:22:44 by dsclearo          #+#    #+#             */
/*   Updated: 2017/03/22 13:22:46 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	insertall(int arr[], int n, int heap[], int *size)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_heapinsert(heap, size, arr[i]);
}

void		ft_arrheapsort(int arr[], int n)
{
	int	heap[n];
	int	size;
	int	i;

	size = -1;
	insertall(arr, n, heap, &size);
	i = -1;
	while (++i < n)
		arr[i] = ft_heapextract(heap, &size);
}
