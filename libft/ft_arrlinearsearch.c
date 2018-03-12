/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlinearsearch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 19:43:36 by dsclearo          #+#    #+#             */
/*   Updated: 2017/02/21 22:30:49 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arrlinearsearch(int arr[], int n, int tosearch)
{
	int		a;

	a = -1;
	while (++a < n)
		if (arr[a] == tosearch)
			return (a);
	return (-1);
}
