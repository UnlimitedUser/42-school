/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:23:45 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/04 15:51:19 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

uintmax_t	extract_unsigned(t_format *arg, va_list *args)
{
	uintmax_t	nbr;

	nbr = va_arg(*args, uintmax_t);
	if (arg->length[0] == 'h' && arg->length[1] == 'h')
		nbr = (unsigned char)nbr;
	else if (arg->length[0] == 'h')
		nbr = (unsigned short int)nbr;
	else if (arg->length[0] == 'l')
		nbr = (unsigned long int)nbr;
	else if (arg->length[0] == 'l' && arg->length[1] == 'l')
		nbr = (unsigned long long int)nbr;
	else if (arg->length[0] == 'j')
		nbr = (uintmax_t)nbr;
	else if (arg->length[0] == 'z')
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
