/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:14:39 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 11:48:00 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

int		handle_unsigned(t_format form, va_list *list)
{
	uintmax_t	n;
	int			len;
	int			num_len;

	n = extract_unsigned(&form, list);
	len = calc_nbrlen_unsigned(n, 10, "", &form);
	num_len = ft_numlen_base_unsigned(n, 10);
	if (form.width > len && !form.flag['-'])
		putchars(form.width - len,
				(char)((form.flag['0'] && n && n != 1) ? '0' : ' '));
	if (form.precision > num_len)
		putchars(form.precision - num_len, '0');
	ft_putnstr(ft_uintmax_ttoa(n), (size_t)len);
	if (form.width > len && form.flag['-'])
		putchars(form.width - len, ' ');
	return ((form.width > len) ? form.width : len);
}
