/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 11:50:36 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/08 11:50:38 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_first(int *a, int size)
{
	*a = -1;
	ft_putstr("           ");
	while (++(*a) < size)
		ft_printf("%11d", *a);
	ft_printf("\n");
	*a = -1;
	ft_putstr("             ");
	while (++(*a) < size * 11)
		ft_printf("%c", '-');
	ft_printf("\n");
	*a = -1;
}

void	print_arr(int **ar, int size)
{
	int		a;
	int		c;

	print_first(&a, size);
	while (++a < size)
	{
		c = 0;
		if (ar[a][0] == 0)
			ft_printf("%11d |%9c", a, ' ');
		else
			ft_printf("%11d |%9d", a, ar[a][0]);
		while (++c < size)
			if (ar[a][c] == 0)
				ft_printf("%11c", ' ');
			else
				ft_printf("%11d", ar[a][c]);
		ft_printf("\n");
	}
}

int		count(char **s)
{
	int		a;

	a = 0;
	while (s[a])
		a++;
	return (a);
}

void	reset(t_graph *graph)
{
	int		a;
	int		b;

	a = -1;
	while (++a < graph->nr_of_nodes)
	{
		b = -1;
		while (++b < graph->nr_of_nodes)
			graph->map[a][b] = 0;
	}
}

void	add_link(t_graph *graph, char **parts)
{
	int		i;
	int		a;

	i = 0;
	while (i < graph->nr_of_nodes && !ft_strequ(graph->nodes[i].name, parts[0]))
		i++;
	if (i == graph->nr_of_nodes)
		exit_on_error("Invalid link: room not found");
	a = 0;
	while (a < graph->nr_of_nodes && !ft_strequ(graph->nodes[a].name, parts[1]))
		a++;
	if (a == graph->nr_of_nodes)
		exit_on_error("Invalid link: room not found");
	graph->map[a][i] = 1;
	graph->map[i][a] = 1;
}
