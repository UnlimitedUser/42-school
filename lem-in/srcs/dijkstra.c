/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:59:48 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/12 11:59:49 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		has_unvisited(int unvisited[], int size)
{
	int		i;

	i = -1;
	while (++i < size)
		if (unvisited[i])
			return (1);
	return (0);
}

int		min_distance(int unvisited[], t_graph *graph)
{
	int		i;
	int		min;
	int		best;

	i = -1;
	best = -1;
	min = INF;
	while (++i < graph->nr_of_nodes)
	{
		if (unvisited[i] && graph->nodes[i].dist < min)
		{
			min = graph->nodes[i].dist;
			best = i;
		}
	}
	return (best);
}

int		get_next(int prev[], int i, t_graph *graph, int start_node)
{
	if (prev[i] == start_node)
		return (i);
	return (get_next(prev, prev[i], graph, start_node));
}

int		search_for_path(int start_node, t_graph *graph,
						int unvisited[], int prev[])
{
	int		v;
	int		u;

	u = start_node;
	while (has_unvisited(unvisited, graph->nr_of_nodes) && !all_used(u, graph))
	{
		u = min_distance(unvisited, graph);
		if (graph->nodes[u].type == end)
			return (get_next(prev, u, graph, start_node));
		unvisited[u] = 0;
		v = -1;
		while (++v < graph->nr_of_nodes)
			if (graph->map[v][u] && graph->nodes[u].dist + 1 <
					graph->nodes[v].dist && !(graph->nodes[v].used &&
					u == start_node && v != graph->end))
			{
				graph->nodes[v].dist = graph->nodes[u].dist + 1;
				prev[v] = u;
			}
	}
	return (-1);
}

int		dijkstra(int start_node, t_graph *graph)
{
	int		i;
	int		unvisited[graph->nr_of_nodes];
	int		prev[graph->nr_of_nodes];

	if (start_node == graph->end)
		return (-1);
	i = -1;
	while (++i < graph->nr_of_nodes)
	{
		unvisited[i] = 1;
		prev[i] = 0;
	}
	graph->nodes[start_node].dist = 0;
	return (search_for_path(start_node, graph, unvisited, prev));
}
