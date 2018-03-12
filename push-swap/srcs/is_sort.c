/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <dsclearo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:58:44 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/09 22:16:46 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_sort(t_stack st_a)
{
	while (st_a.top > 0)
	{
		if (st_a.arr[st_a.top] > st_a.arr[st_a.top - 1])
			return (0);
		st_a.top--;
	}
	return (1);
}
