/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrrecursiveinsertionsort.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:46:51 by dsclearo          #+#    #+#             */
/*   Updated: 2017/02/21 19:59:54 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	internal(int arr[], int curr, int n)
{
	int	key;

	if (!curr)
		return ;
	internal(arr, curr - 1, n);
	key = arr[curr];
	while (--curr > -1 && key < arr[curr])
		arr[curr + 1] = arr[curr];
	arr[curr + 1] = key;
}

void		ft_arrrecursiveinsertionsort(int arr[], int n)
{
	internal(arr, n - 1, n);
}
