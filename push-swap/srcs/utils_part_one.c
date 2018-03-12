/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_part_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 20:02:58 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/30 20:03:03 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack *st_a, t_stack *st_b)
{
	if (st_b->top >= 0)
		st_a->arr[++st_a->top] = st_b->arr[st_b->top--];
}

void	pb(t_stack *st_a, t_stack *st_b)
{
	if (st_a->top >= 0)
		st_b->arr[++st_b->top] = st_a->arr[st_a->top--];
}

void	sa(t_stack *st_a)
{
	int	tmp;

	if (st_a->top < 1)
		return ;
	tmp = st_a->arr[st_a->top];
	st_a->arr[st_a->top] = st_a->arr[st_a->top - 1];
	st_a->arr[st_a->top - 1] = tmp;
}

void	sb(t_stack *st_b)
{
	int tmp;

	if (st_b->top < 1)
		return ;
	tmp = st_b->arr[st_b->top];
	st_b->arr[st_b->top] = st_b->arr[st_b->top - 1];
	st_b->arr[st_b->top - 1] = tmp;
}

void	ss(t_stack *st_a, t_stack *st_b)
{
	sa(st_a);
	sb(st_b);
}
