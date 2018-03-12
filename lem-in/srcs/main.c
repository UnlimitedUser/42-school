/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:37:55 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/18 22:28:47 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(int ac, char **av)
{
	t_graph	graph;

	graph.verbose = 0;
	if (ac == 2 && !ft_strequ("-v", av[1]))
		exit_on_error("Usage: ./lem-in [-v] < map");
	else if (ac != 1 && ac != 2)
		exit_on_error("Usage: ./lem-in [-v] < map");
	else if (ac == 2)
		graph.verbose = 1;
	put_in_graph(&graph);
	if (graph.verbose)
	{
		ft_printf("Successfully read from stdin, "
						"printing graph connections:\n");
		print_arr(graph.map, graph.nr_of_nodes);
	}
	solve(graph);
	return (0);
}
