/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:30:19 by dsclearo          #+#    #+#             */
/*   Updated: 2016/10/23 14:16:56 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		if (root->left)
		{
			ft_btree_apply_infix(root->left, applyf);
		}
		applyf(root->item);
		if (root->right)
		{
			ft_btree_apply_infix(root->right, applyf);
		}
	}
}
