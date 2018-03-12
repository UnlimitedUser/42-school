/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 14:25:33 by dsclearo          #+#    #+#             */
/*   Updated: 2016/10/21 18:07:17 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int		count;
	int		*a;

	if (min >= max)
	{
		return (NULL);
	}
	a = (int*)malloc(sizeof(int) * (max - min));
	count = 0;
	while (min < max)
	{
		a[count] = min;
		min++;
		count++;
	}
	return (a);
}
