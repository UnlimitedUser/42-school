/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrselectionsort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 18:30:38 by dsclearo          #+#    #+#             */
/*   Updated: 2017/03/02 17:09:48 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		min(int arr[], int last, int n)
{
	int		min;

	min = last;
	while (++last < n)
		if (arr[last] < arr[min])
			min = last;
	return (min);
}

void			ft_arrselectionsort(int arr[], int n)
{
	int		last;
	int		a;
	int		tmp;

	last = -1;
	while (++last < n - 1)
	{
		a = min(arr, last, n);
		tmp = arr[last];
		arr[last] = arr[a];
		arr[a] = tmp;
	}
}
