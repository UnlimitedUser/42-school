/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:37:07 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 11:55:55 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

intmax_t	extract_signed(t_format *arg, va_list *args)
{
	intmax_t	nbr;

	nbr = va_arg(*args, intmax_t);
	if (arg->length[0] == 'h' && arg->length[1] == 'h')
		nbr = (char)nbr;
	else if (arg->length[0] == 'h')
		nbr = (short int)nbr;
	else if (arg->length[0] == 'l')
		nbr = (long int)nbr;
	else if (arg->length[0] == 'l' && arg->length[1] == 'l')
		nbr = (long long int)nbr;
	else if (arg->length[0] == 'j')
		nbr = (intmax_t)nbr;
	else if (arg->length[0] == 'z')
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}
