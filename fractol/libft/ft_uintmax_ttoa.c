/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmax_ttoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:17:57 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/15 15:03:59 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*ft_nbrstr(uintmax_t nb, char *str, unsigned int pos)
{
	pos--;
	if (nb >= 10)
	{
		ft_nbrstr((nb / 10), str, pos);
		str[pos] = ((nb % 10) + '0');
	}
	else
		str[pos] = (nb + '0');
	return (str);
}

static unsigned int		ft_lennbr(uintmax_t n)
{
	unsigned int	count;

	count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char					*ft_uintmax_ttoa(uintmax_t n)
{
	unsigned int	len;
	char			*str;

	len = ft_lennbr(n);
	if (n == 0)
	{
		if ((!(str = ft_strnew(1))))
			return (NULL);
		str[0] = '0';
	}
	else
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		str = ft_nbrstr(n, str, len);
	}
	return (str);
}
