/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 20:30:13 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/10 14:42:13 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		rt_putchars(int len, char c)
{
	while (len--)
		ft_putchar(c);
}

void			show_stacks(t_stack st_a, t_stack st_b)
{
	int	max;
	int	n;

	max = MAX(st_a.top, st_b.top);
	while (max >= 0)
	{
		n = 0;
		if (max <= st_a.top)
		{
			ft_putnbr(st_a.arr[max]);
			n = ft_numlen(st_a.arr[max]);
		}
		if (max <= st_b.top)
		{
			rt_putchars(11 - n, ' ');
			ft_putnbr(st_b.arr[max]);
		}
		ft_putchar('\n');
		max--;
	}
	ft_putstr("-          -\n");
}
