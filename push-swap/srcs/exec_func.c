/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:19:58 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/09 17:19:59 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	verbose(int v, char *line)
{
	if (v)
		ft_printf("Executing %s:\n", line);
}

void	exec_func(char *line, t_stack *st_a, t_stack *st_b, int v)
{
	if (ft_strequ(line, "sa"))
		sa(st_a);
	else if (ft_strequ(line, "sb"))
		sb(st_b);
	else if (ft_strequ(line, "ss"))
		ss(st_a, st_b);
	else if (ft_strequ(line, "pa"))
		pa(st_a, st_b);
	else if (ft_strequ(line, "pb"))
		pb(st_a, st_b);
	else if (ft_strequ(line, "ra"))
		ra(st_a);
	else if (ft_strequ(line, "rb"))
		rb(st_b);
	else if (ft_strequ(line, "rr"))
		rr(st_a, st_b);
	else if (ft_strequ(line, "rra"))
		rra(st_a);
	else if (ft_strequ(line, "rrb"))
		rrb(st_b);
	else if (ft_strequ(line, "rrr"))
		rrr(st_a, st_b);
	else
		exit_on_error();
	verbose(v, line);
}
