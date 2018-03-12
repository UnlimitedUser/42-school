/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:24:15 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/07 16:26:36 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

# define SIZE 50
# define INF 2147483647

typedef enum			e_type
{
	regular,
	start,
	end
}						t_type;

typedef struct			s_node
{
	int					dist;
	char				*name;
	t_type				type;
	int					ants;
	int					used;
}						t_node;

typedef struct			s_graph
{
	struct s_node		nodes[SIZE];
	int					**map;
	int					nr_of_ants;
	int					nr_of_nodes;
	int					start;
	int					end;
	int					verbose;
}						t_graph;

void					exit_on_error(char *str);
void					add_link(t_graph *graph, char **parts);
void					reset(t_graph *graph);
int						count(char **s);
void					put_in_graph(t_graph *graph);
void					print_arr(int **ar, int size);
char					*skip_zero(char *str);
void					validate(t_graph *graph);
void					solve(t_graph graph);
int						ft_strisnum(char *s);
int						dijkstra(int start, t_graph *graph);
int						all_used(int a, t_graph *graph);
void					initialize_map(t_graph *graph);

#endif
