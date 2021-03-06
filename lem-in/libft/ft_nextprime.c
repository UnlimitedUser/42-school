/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextprime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 18:55:06 by dsclearo          #+#    #+#             */
/*   Updated: 2016/10/21 19:03:15 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nextprime(int nbr)
{
	while (++nbr)
		if (ft_isprime(nbr))
			return (nbr);
	return (0);
}
