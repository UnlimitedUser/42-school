/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 21:44:06 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 11:58:52 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

int		ft_numlen_base_unsigned(uintmax_t nbr, int base)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

int		ft_numlen_base_signed(intmax_t nbr, int base)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	return (i);
}
