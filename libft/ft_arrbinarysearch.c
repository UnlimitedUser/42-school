/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrbinarysearch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:02:23 by dsclearo          #+#    #+#             */
/*   Updated: 2017/03/02 17:09:46 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arrbinarysearch(int arr[], int n, int tofind)
{
	int		up;
	int		low;
	int		mid;

	up = n - 1;
	low = 0;
	while (up >= low)
	{
		mid = (up + low) / 2;
		if (arr[mid] == tofind)
			return (mid);
		else if (arr[mid] > tofind)
			up = mid - 1;
		else if (arr[mid] < tofind)
			low = mid + 1;
	}
	return (-1);
}
