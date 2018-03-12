/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 22:00:15 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/15 14:18:14 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	init_values(t_graph *graph, int a)
{
	int		i;

	i = -1;
	while (++i < graph->nr_of_nodes)
	{
		graph->nodes[i].dist = INF;
		if (a)
			graph->nodes[i].used = 0;
	}
}

void	reset_graph_pos(int ants[], int size, int start_node)
{
	int		i;

	i = -1;
	while (++i < size)
		ants[i] = start_node;
}

void	helper(t_graph *graph, int n, int *i, int ants_position[])
{
	init_values(graph, 0);
	graph->nodes[n].used = 1;
	graph->nodes[n].ants++;
	graph->nodes[ants_position[*i]].ants--;
	ants_position[*i] = n;
}

void	print(t_graph *graph, int *a, int i, int n)
{
	if (!*a)
	{
		ft_printf("L%d-%s", i + 1, graph->nodes[n].name);
		*a = 1;
	}
	else
		ft_printf(" L%d-%s", i + 1, graph->nodes[n].name);
}

void	solve(t_graph graph)
{
	int		i;
	int		n;
	int		a;
	int		ants_position[graph.nr_of_ants];

	reset_graph_pos(ants_position, graph.nr_of_ants, graph.start);
	while (graph.nodes[graph.end].ants != graph.nr_of_ants)
	{
		i = -1;
		a = 0;
		init_values(&graph, 1);
		while (++i < graph.nr_of_ants)
		{
			if ((n = dijkstra(ants_position[i], &graph)) == -1 ||
					(graph.nodes[n].used && n != graph.end))
				continue ;
			helper(&graph, n, &i, ants_position);
			print(&graph, &a, i, n);
		}
		if (a == 0)
			exit_on_error("No path from start to end");
		ft_printf("\n");
	}
}
