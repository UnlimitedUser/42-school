/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 22:13:39 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/10 14:25:51 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_stack
{
	int			arr[1000];
	int			top;
}				t_stack;

void			put_in_stack(t_stack *st_a, int ac, char **av);
void			exit_on_error();
void			pa(t_stack *st_a, t_stack *st_b);
void			pb(t_stack *st_a, t_stack *st_b);
void			sa(t_stack *st_a);
void			sb(t_stack *st_b);
void			ss(t_stack *st_a, t_stack *st_b);
void			ra(t_stack *st_a);
void			rb(t_stack *st_b);
void			rr(t_stack *st_a, t_stack *st_b);
void			rra(t_stack *st_a);
void			rrb(t_stack *st_b);
void			rrr(t_stack *st_a, t_stack *st_b);
void			show_stacks(t_stack st_a, t_stack st_b);
int				is_sort(t_stack st_a);
void			exec_func(char *line, t_stack *st_a, t_stack *st_b,
						int v);
void			flag_v(int *ac, char **av, int *i);

#endif
