/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 18:42:14 by dsclearo          #+#    #+#             */
/*   Updated: 2016/10/21 18:53:58 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprime(int nbr)
{
	int		a;

	a = 1;
	while (++a < nbr)
		if (nbr % a == 0)
			return (0);
	return (1);
}
