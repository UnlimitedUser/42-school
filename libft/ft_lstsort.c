/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:18:07 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/31 15:18:08 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap(void **a, void **b)
{
	void	*aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	ft_lstsort(t_list *list, int (*cmp)(t_list *, t_list *))
{
	t_list	*lst;
	int		s;

	s = 1;
	while (s)
	{
		lst = list;
		s = 0;
		while (lst && lst->next)
		{
			if (cmp(lst, lst->next) > 0)
			{
				swap(&lst->content, &lst->next->content);
				s = 1;
			}
			lst = lst->next;
		}
	}
}
