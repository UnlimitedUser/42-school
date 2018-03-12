/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_used.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:18:15 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/14 13:18:16 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		all_used(int a, t_graph *graph)
{
	int		i;

	i = -1;
	while (++i < graph->nr_of_nodes)
		if (!graph->nodes[i].used && graph->map[i][a])
			return (0);
	return (1);
}
