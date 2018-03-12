/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrquicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:27:02 by dsclearo          #+#    #+#             */
/*   Updated: 2017/03/22 20:27:03 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partition(int arr[], int n, int low, int high)
{
	int		p;
	int		fhigh;
	int		a;

	p = high;
	a = low - 1;
	fhigh = low;
	while (++a < high)
		if (arr[a] < arr[p])
		{
			ft_heapswap(arr, n, a, fhigh);
			fhigh++;
		}
	ft_heapswap(arr, n, p, fhigh);
	return (fhigh);
}

static void	helper(int arr[], int n, int low, int high)
{
	int		p;

	if (low < high)
	{
		p = partition(arr, n, low, high);
		helper(arr, n, low, p - 1);
		helper(arr, n, p + 1, high);
	}
}

void		ft_arrquicksort(int arr[], int n)
{
	helper(arr, n, 0, n - 1);
}
