/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_nbrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 21:38:07 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 11:57:36 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

int	calc_nbrlen_unsigned(uintmax_t nbr, int base, char *p, t_format *arg)
{
	int	nbr_len;
	int	nbrstr;

	nbr_len = ft_numlen_base_unsigned(nbr, base);
	if (nbr == 0 && arg->has_precision && !arg->precision)
		nbrstr = 0;
	else if (arg->has_precision)
		nbrstr = MAX(nbr_len, arg->precision);
	else
		nbrstr = nbr_len;
	if (((arg->flag[' '] || arg->flag['+'])) && p && nbr)
		nbrstr += ft_strlen(p);
	return (nbrstr);
}

int	calc_nbrlen_signed(intmax_t nbr, int base, char *p, t_format *arg)
{
	int	nbr_len;
	int	nbrstr;

	nbr_len = ft_numlen_base_signed(nbr, base);
	if (nbr == 0 && arg->has_precision && !arg->precision)
		nbrstr = 0;
	else if (arg->has_precision)
		nbrstr = MAX(nbr_len, arg->precision);
	else
		nbrstr = nbr_len;
	if ((arg->flag[' '] || arg->flag['+'] || nbr < 0) && p)
		nbrstr += ft_strlen(p);
	return (nbrstr);
}
