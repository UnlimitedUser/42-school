/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 15:16:13 by dsclearo          #+#    #+#             */
/*   Updated: 2016/10/21 18:11:54 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	range[0] = NULL;
	if (min < max)
	{
		range[0] = (int*)malloc(sizeof(int) * (max - min));
		if (range[0])
		{
			i = 0;
			while (min < max)
			{
				range[0][i] = min;
				i++;
				min++;
			}
			return (i);
		}
	}
	return (0);
}
