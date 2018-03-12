/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 11:53:01 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/18 22:31:27 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	handle_command(t_graph *graph, char *line, int *index,
							t_node *node)
{
	char	**parts;

	if (ft_strequ(line, "##start"))
		node->type = start;
	else if (ft_strequ(line, "##end"))
		node->type = end;
	else
	{
		free(line);
		(*index)--;
		return ;
	}
	free(line);
	if (!get_next_line(0, &line))
		exit_on_error("No statement after command");
	parts = ft_strsplit(line, ' ');
	if (count(parts) != 3 || !ft_strisnum(parts[1]) || !ft_strisnum(parts[2]))
		exit_on_error("Wrong statement after special command");
	node->name = parts[0];
	graph->nodes[*index] = *node;
}

void		handle_vertexes(t_graph *graph, char *line)
{
	char	**parts;

	initialize_map(graph);
	reset(graph);
	parts = ft_strsplit(line, '-');
	if (count(parts) != 2)
		exit_on_error("Specify more arguments");
	add_link(graph, parts);
	free(line);
	while (get_next_line(0, &line))
	{
		if (count(parts) != 2)
			exit_on_error("Specify more arguments");
		parts = ft_strsplit(line, '-');
		add_link(graph, parts);
		free(line);
	}
}

int			handle_node(t_graph *graph, int index, t_node *node,
						char **parts)
{
	if (count(parts) != 3)
		return (0);
	else if (!ft_strisnum(parts[1]) || !ft_strisnum(parts[2]))
		exit_on_error("Coords must be int");
	node->name = parts[0];
	graph->nodes[index] = *node;
	return (1);
}

void		checks(t_graph *graph, int *index, char **line)
{
	*index = 0;
	if (!get_next_line(0, line))
		exit_on_error("Please add more info");
	if (!ft_strequ(ft_itoa(ft_atoi(*line)), skip_zero(*line)))
		exit_on_error("Invalid nr. of ants");
	graph->nr_of_ants = ft_atoi(*line);
}

void		put_in_graph(t_graph *graph)
{
	char	*line;
	t_node	node;
	char	**parts;
	int		index;

	checks(graph, &index, &line);
	while (1)
	{
		if (!get_next_line(0, &line))
			exit_on_error("Please add more info");
		node.type = regular;
		if (*line == '#')
			handle_command(graph, line, &index, &node);
		else
		{
			parts = ft_strsplit(line, ' ');
			if (!handle_node(graph, index, &node, parts))
				break ;
		}
		index++;
	}
	graph->nr_of_nodes = index;
	handle_vertexes(graph, line);
	validate(graph);
}
