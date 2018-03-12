/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_part_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 20:16:24 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/10 14:44:12 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *st_a)
{
	int	top;
	int	i;

	if (st_a->top < 1)
		return ;
	top = st_a->arr[st_a->top];
	i = st_a->top + 1;
	while (--i > 0)
		st_a->arr[i] = st_a->arr[i - 1];
	st_a->arr[0] = top;
}

void	rb(t_stack *st_b)
{
	int	top;
	int	i;

	if (st_b->top < 1)
		return ;
	top = st_b->arr[st_b->top];
	i = st_b->top + 1;
	while (--i > 0)
		st_b->arr[i] = st_b->arr[i - 1];
	st_b->arr[0] = top;
}

void	rr(t_stack *st_a, t_stack *st_b)
{
	ra(st_a);
	rb(st_b);
}
