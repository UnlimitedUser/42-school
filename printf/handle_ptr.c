/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 22:04:15 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 12:01:38 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

#define A ((len > form.precision) ? len : form.precision)

int		handle_ptr(t_format form, va_list *list)
{
	char		*str;
	int			len;
	int			l_len;

	str = ft_uintmax_ttoa_base((uintmax_t)((long)(unsigned *)
				va_arg(*list, void *)), 16);
	len = (*str == '0' && form.precision >= 0 && !form.has_width &&
			form.has_precision) ? 0 : (int)ft_strlen(str);
	l_len = (form.has_precision) ? A : len;
	if (form.has_width && !form.flag['-'] && form.width > l_len + 2)
		putchars(form.width - l_len - 2, (char)(form.flag['0'] ? '0' : ' '));
	ft_putstr("0x");
	if (form.precision > len)
		putchars(form.precision - len, '0');
	ft_putnstr(str, (size_t)len);
	if (form.has_width && form.flag['-'] && form.width > form.precision)
		print_spaces((size_t)form.width - l_len - 2);
	return (MAX(l_len + 2, form.width));
}
