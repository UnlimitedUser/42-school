/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:00:13 by dsclearo          #+#    #+#             */
/*   Updated: 2016/11/21 14:53:22 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_bigger(int a, int b)
{
	return (a < b ? b : a);
}

int		ft_vert(t_vector vectors[26][4], int nr)
{
	return (ft_bigger(ft_bigger(ft_bigger(vectors[nr][2].x, vectors[nr][1].x),
					vectors[nr][3].x), vectors[nr][0].x));
}

int		ft_oriz(t_vector vectors[26][4], int nr)
{
	return (ft_bigger(ft_bigger(ft_bigger(vectors[nr][2].y, vectors[nr][1].y),
					vectors[nr][3].y), vectors[nr][0].y));
}
