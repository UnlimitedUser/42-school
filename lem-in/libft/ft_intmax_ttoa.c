/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmax_ttoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:30:19 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 11:49:04 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*ft_nbrstr(intmax_t n, char *str, unsigned int pos)
{
	intmax_t	nb;

	pos--;
	if (n < 0)
	{
		nb = -n;
		str[0] = '-';
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_nbrstr((nb / 10), str, pos);
		str[pos] = ((nb % 10) + '0');
	}
	else
		str[pos] = (nb + '0');
	return (str);
}

static unsigned int		ft_lennbr(intmax_t n)
{
	unsigned int	count;
	uintmax_t		nb;

	count = 0;
	if (n < 0)
	{
		nb = (uintmax_t)-n;
		count++;
	}
	else
		nb = (uintmax_t)n;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char					*ft_intmax_ttoa(intmax_t n)
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
	else if (n == INTMAX_MIN)
	{
		str = "-9223372036854775808";
		return (str);
	}
	else
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		str = ft_nbrstr(n, str, len);
	}
	return (str);
}
