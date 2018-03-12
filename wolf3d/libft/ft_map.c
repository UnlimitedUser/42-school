/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 12:52:21 by dsclearo          #+#    #+#             */
/*   Updated: 2016/09/12 13:07:13 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*res;
	int	c;

	c = 0;
	res = (int *)malloc(sizeof(int) * length);
	while (c < length)
	{
		res[c] = f(tab[c]);
		c++;
	}
	return (res);
}
