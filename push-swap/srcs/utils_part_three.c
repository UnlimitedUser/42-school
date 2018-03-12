/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_part_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:46:28 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/30 21:46:32 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *st_a)
{
	int	first;
	int	i;

	if (st_a->top < 1)
		return ;
	first = st_a->arr[0];
	i = -1;
	while (++i < st_a->top)
		st_a->arr[i] = st_a->arr[i + 1];
	st_a->arr[st_a->top] = first;
}

void	rrb(t_stack *st_b)
{
	int	first;
	int	i;

	if (st_b->top < 1)
		return ;
	first = st_b->arr[0];
	i = -1;
	while (++i < st_b->top)
		st_b->arr[i] = st_b->arr[i + 1];
	st_b->arr[st_b->top] = first;
}

void	rrr(t_stack *st_a, t_stack *st_b)
{
	rra(st_a);
	rrb(st_b);
}
