/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrinsertionsort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:04:59 by dsclearo          #+#    #+#             */
/*   Updated: 2017/02/21 22:30:48 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrinsertionsort(int arr[], int n)
{
	int	i;
	int	j;
	int	key;

	i = 0;
	while (++i < n)
	{
		key = arr[i];
		j = i;
		while (--j > -1 && key < arr[j])
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}
}
