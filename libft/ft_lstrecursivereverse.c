/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrecursivereverse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 22:31:10 by dsclearo          #+#    #+#             */
/*   Updated: 2017/03/21 19:09:38 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_helper(t_list *prev, t_list *up, t_list **head)
{
	*head = up;
	if (up->next)
		ft_helper(up, up->next, head);
	up->next = prev;
}

void		ft_lstrecursivereverse(t_list **head)
{
	ft_helper(NULL, *head, head);
}
