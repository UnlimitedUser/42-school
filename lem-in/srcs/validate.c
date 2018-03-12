/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:07:46 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/11 15:07:47 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check(t_graph *graph, int i, int *is_start, int *is_end)
{
	if (graph->nodes[i].name[0] == 'L')
		exit_on_error("L used in room name");
	if (graph->nodes[i].type == start)
	{
		if (*is_start)
			exit_on_error("Two start declarations");
		graph->nodes[i].ants = graph->nr_of_ants;
		graph->start = i;
		*is_start = 1;
	}
	else if (graph->nodes[i].type == end)
	{
		if (*is_end)
			exit_on_error("Two end declarations");
		graph->end = i;
		*is_end = 1;
	}
}

void	validate(t_graph *graph)
{
	int		i;
	int		is_start;
	int		is_end;

	i = -1;
	is_start = 0;
	is_end = 0;
	while (++i < graph->nr_of_nodes)
		check(graph, i, &is_start, &is_end);
	if (!is_start || !is_end)
		exit_on_error("No start or end commands");
}
