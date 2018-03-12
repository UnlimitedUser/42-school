/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:32:58 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/15 14:18:44 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		initialize_map(t_graph *graph)
{
	int		a;

	a = -1;
	graph->map = (int **)malloc(sizeof(int *) * graph->nr_of_nodes);
	while (++a < graph->nr_of_nodes)
		graph->map[a] = (int *)malloc(sizeof(int) * graph->nr_of_nodes);
}
