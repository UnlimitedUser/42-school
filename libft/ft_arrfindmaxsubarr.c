/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfindmaxsubarr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:46:59 by dsclearo          #+#    #+#             */
/*   Updated: 2017/03/20 22:23:15 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	a(int arr[], int s)
{
	arr[0] = MININT;
	arr[1] = MININT;
	arr[2] = s;
	arr[3] = 0;
}

static void	b(int arr[], int z, int d, int c)
{
	arr[0] = z;
	arr[1] = d;
	arr[2] = c;
}

static void	findcross(int arr[], int array[], int cross[3])
{
	int		bestsum[4];

	a(bestsum, array[1] + 1);
	while (--bestsum[2] > array[0])
	{
		bestsum[3] += arr[bestsum[2]];
		if (bestsum[3] > bestsum[0])
		{
			cross[0] = bestsum[2];
			bestsum[0] = bestsum[3];
		}
	}
	bestsum[3] = 0;
	bestsum[2] = array[1];
	while (++bestsum[2] < array[2])
	{
		bestsum[3] += arr[bestsum[2]];
		if (bestsum[3] > bestsum[1])
		{
			cross[1] = bestsum[2];
			bestsum[1] = bestsum[3];
		}
	}
	cross[2] = bestsum[0] + bestsum[1];
}

static void	maxsubarr(int arr[], int low, int high, int array[3])
{
	int		l[3];
	int		r[3];
	int		cross[3];
	int		mid[4];

	if (low == high)
		b(array, low, high, arr[low]);
	else
	{
		mid[3] = (low + high) / 2;
		maxsubarr(arr, low, mid[3], l);
		maxsubarr(arr, mid[3] + 1, high, r);
		b(mid, low, mid[3], high);
		findcross(arr, mid, cross);
		if (l[2] > r[2] && l[2] > cross[2])
			b(array, l[0], l[1], l[2]);
		else if (r[2] > l[2] && r[2] > cross[2])
			b(array, r[0], r[1], r[2]);
		else
			b(array, cross[0], cross[1], cross[2]);
	}
}

int			ft_arrfindmaxsubarr(int arr[], int n, int *start, int *end)
{
	int		array[3];

	array[0] = 0;
	array[1] = n;
	array[2] = 0;
	maxsubarr(arr, 0, n - 1, array);
	*start = array[0];
	*end = array[1];
	return (array[2]);
}
