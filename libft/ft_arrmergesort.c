/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrmergesort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 19:46:33 by dsclearo          #+#    #+#             */
/*   Updated: 2017/03/02 17:09:45 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	merge(int arr[], int start, int mid, int size)
{
	int	l[(mid - start + 1)];
	int	r[(size - mid)];
	int	n[5];

	n[0] = mid - start + 1;
	n[1] = size - mid;
	n[2] = -1;
	while (++n[2] < n[0])
		l[n[2]] = arr[start + n[2]];
	n[2] = -1;
	while (++n[2] < n[1])
		r[n[2]] = arr[mid + 1 + n[2]];
	n[3] = 0;
	n[4] = 0;
	while (n[3] < n[0] && n[4] < n[1])
	{
		if (l[n[3]] <= r[n[4]])
			arr[start] = l[n[3]++];
		else
			arr[start] = r[n[4]++];
		start++;
	}
	while (n[3] < n[0])
		arr[start++] = l[n[3]++];
	while (n[4] < n[1])
		arr[start++] = r[n[4]++];
}

static void	init(int arr[], int start, int n)
{
	int		q;

	if (start < n)
	{
		q = (start + n) / 2;
		init(arr, start, q);
		init(arr, q + 1, n);
		merge(arr, start, q, n);
	}
}

void		ft_arrmergesort(int arr[], int n)
{
	init(arr, 0, n - 1);
}
