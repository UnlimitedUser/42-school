/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 22:33:15 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/10 14:46:00 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		exec_instructions(t_stack *st_a, t_stack *st_b, int v)
{
	char	*line;

	if (v)
		show_stacks(*st_a, *st_b);
	while (get_next_line(0, &line))
	{
		exec_func(line, st_a, st_b, v);
		if (v)
			show_stacks(*st_a, *st_b);
		free(line);
	}
	if (st_b->top == -1 && is_sort(*st_a))
		ft_putendl("OK");
	else
		ft_putendl("KO");
}

int				main(int ac, char **av)
{
	t_stack	st_b;
	t_stack st_a;
	int		verbose;

	if (ac == 1)
		exit_on_error();
	st_a.top = -1;
	st_b.top = -1;
	verbose = 0;
	if (ft_strequ("-v", av[1]))
	{
		av++;
		ac--;
		verbose = 1;
	}
	put_in_stack(&st_a, ac, av);
	exec_instructions(&st_a, &st_b, verbose);
	return (0);
}
