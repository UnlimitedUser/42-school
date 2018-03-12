/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrrecursivebinarysearch.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 20:01:48 by dsclearo          #+#    #+#             */
/*   Updated: 2017/02/24 17:27:32 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int			ft_a(int arr[], int start, int n, int tofind)
{
	int		mid;

	if (start > n)
		return (-1);
	mid = (n + start) / 2;
	if (arr[mid] == tofind)
		return (mid);
	else if (arr[mid] < tofind)
		return (ft_a(arr, mid + 1, n, tofind));
	else if (arr[mid] > tofind)
		return (ft_a(arr, start, mid - 1, tofind));
	return (-1);
}

int					ft_arrrecursivebinarysearch(int arr[], int n, int tofind)
{
	return (ft_a(arr, 0, n - 1, tofind));
}
