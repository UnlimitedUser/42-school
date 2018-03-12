/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmax_ttoa_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 21:00:53 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 11:50:21 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*ft_nbrstr(uintmax_t nb, char *str,
		unsigned int pos, int base)
{
	char	*arr;

	arr = "0123456789abcdef";
	pos--;
	if (nb >= (uintmax_t)base)
	{
		ft_nbrstr((nb / base), str, pos, base);
		str[pos] = ((arr[nb % base]));
	}
	else
		str[pos] = (arr[nb]);
	return (str);
}

static unsigned int		ft_lennbr(uintmax_t n, int base)
{
	unsigned int	count;

	count = 0;
	while (n > 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}

char					*ft_uintmax_ttoa_base(uintmax_t n, int base)
{
	unsigned int	len;
	char			*str;

	len = ft_lennbr(n, base);
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
		str = ft_nbrstr(n, str, len, base);
	}
	return (str);
}
