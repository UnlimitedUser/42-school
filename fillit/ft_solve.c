/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:16:21 by dsclearo          #+#    #+#             */
/*   Updated: 2016/11/21 14:59:40 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_place(t_vector vectors[27][4], char ***map, int nr, int tab[2])
{
	int		a;
	int		b;

	a = tab[0];
	b = tab[1];
	if (vectors[nr][0].x + a < g_size && vectors[nr][0].y + b < g_size &&
			vectors[nr][1].x + a < g_size && vectors[nr][1].y + b < g_size &&
			vectors[nr][2].x + a < g_size && vectors[nr][2].y + b < g_size &&
			vectors[nr][3].x + a < g_size && vectors[nr][3].y + b < g_size &&
			(*map)[vectors[nr][0].x + a][vectors[nr][0].y + b] == '.' &&
			(*map)[vectors[nr][1].x + a][vectors[nr][1].y + b] == '.' &&
			(*map)[vectors[nr][2].x + a][vectors[nr][2].y + b] == '.' &&
			(*map)[vectors[nr][3].x + a][vectors[nr][3].y + b] == '.')
	{
		(*map)[vectors[nr][0].x + a][vectors[nr][0].y + b] = (char)('A' + nr);
		(*map)[vectors[nr][1].x + a][vectors[nr][1].y + b] = (char)('A' + nr);
		(*map)[vectors[nr][2].x + a][vectors[nr][2].y + b] = (char)('A' + nr);
		(*map)[vectors[nr][3].x + a][vectors[nr][3].y + b] = (char)('A' + nr);
		return (1);
	}
	else
		return (0);
}

void	ft_rem(t_vector vectors[27][4], char ***map, int nr, int tab[2])
{
	int		a;
	int		b;

	a = tab[0];
	b = tab[1];
	(*map)[vectors[nr][0].x + a][vectors[nr][0].y + b] = '.';
	(*map)[vectors[nr][1].x + a][vectors[nr][1].y + b] = '.';
	(*map)[vectors[nr][2].x + a][vectors[nr][2].y + b] = '.';
	(*map)[vectors[nr][3].x + a][vectors[nr][3].y + b] = '.';
}

int		high_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

int		ft_solve(t_vector vectors[27][4], char ***map, int nr)
{
	int		x;
	int		y;
	int		tab[2];

	x = -1;
	y = -1;
	if (vectors[nr][0].x == -1)
		return (1);
	while (++x < g_size - ft_vert(vectors, nr))
	{
		while (++y < g_size - ft_oriz(vectors, nr))
		{
			tab[0] = x;
			tab[1] = y;
			if (ft_place(vectors, map, nr, tab))
			{
				if (ft_solve(vectors, map, nr + 1))
					return (1);
				else
					ft_rem(vectors, map, nr, tab);
			}
		}
		y = -1;
	}
	return (0);
}

char	**ft_init_solve(t_vector vectors[27][4], int tetris)
{
	char	**map;

	g_size = high_sqrt(tetris * 4);
	map = ft_newmap();
	while (!ft_solve(vectors, &map, 0))
	{
		g_size++;
		ft_memdela((void ***)&map);
		map = ft_newmap();
	}
	return (map);
}
