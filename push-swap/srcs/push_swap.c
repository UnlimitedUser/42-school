/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 12:21:12 by dsclearo          #+#    #+#             */
/*   Updated: 2017/02/28 17:23:26 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		call_func(t_stack *st_a, t_stack *st_b, int w[],
		char *instr[1000])
{
	if (!w[0] && st_a->top > 1)
		instr[w[1]] = "sa";
	else if (w[0] == 1 && st_b->top > 1)
		instr[w[1]] = "sb";
	else if (w[0] == 2 && st_a->top > 1 && st_b->top > 1)
		instr[w[1]] = "ss";
	else if (w[0] == 3 && st_b->top >= 0)
		instr[w[1]] = "pa";
	else if (w[0] == 4 && st_a->top >= 0)
		instr[w[1]] = "pb";
	else if (w[0] == 5 && st_a->top > 1)
		instr[w[1]] = "ra";
	else if (w[0] == 6 && st_b->top > 1)
		instr[w[1]] = "rb";
	else if (w[0] == 7 && st_a->top > 1 && st_b->top > 1)
		instr[w[1]] = "rr";
	else if (w[0] == 8 && st_a->top > 1)
		instr[w[1]] = "rra";
	else if (w[0] == 9 && st_b->top > 1)
		instr[w[1]] = "rrb";
	else if (w[0] == 10 && st_a->top > 1 && st_b->top > 1)
		instr[w[1]] = "rrr";
	else
		return (0);
	return (1);
}

static void		print_instructs(char *instructs[1000], int size)
{
	int	i;

	i = -1;
	while (++i < size + 1)
		ft_putendl(instructs[i]);
}

void			apply(t_stack *st_a, t_stack *st_b, int *a,
		char *instr[1000])
{
	int		i;

	i = -1;
	if (a[2])
		show_stacks(*st_a, *st_b);
	while (++i < a[1] + 1)
	{
		exec_func(instr[i], st_a, st_b, a[2]);
		if (a[2])
			show_stacks(*st_a, *st_b);
	}
}

static int		solve(t_stack st_a, t_stack st_b,
		char *instructs[1000], int i[3])
{
	int	w[2];

	if (i[0] == i[1])
	{
		apply(&st_a, &st_b, i, instructs);
		if (st_b.top == -1 && is_sort(st_a))
			return (1);
		if (i[2])
			ft_printf("Incorrect commands\n");
		return (0);
	}
	i[0]++;
	w[1] = i[0];
	w[0] = -1;
	while (++w[0] < 11)
	{
		if (!(call_func(&st_a, &st_b, w, instructs)))
			continue ;
		if (solve(st_a, st_b, instructs, i))
			return (1);
	}
	i[0]--;
	return (0);
}

int				main(int ac, char **av)
{
	t_stack	st_a;
	t_stack st_b;
	int		i[3];
	char	*instructs[1000];

	if (ac == 1)
		exit_on_error();
	st_a.top = -1;
	st_b.top = -1;
	i[2] = 0;
	flag_v(&ac, av, i);
	put_in_stack(&st_a, ac, av);
	i[0] = -1;
	i[1] = -1;
	while (!solve(st_a, st_b, instructs, i))
	{
		i[0] = -1;
		i[1]++;
		if (i[2])
			ft_printf("Didn't work, lets try %d step(s)\n", i[1] + 1);
	}
	print_instructs(instructs, i[1]);
	return (0);
}
