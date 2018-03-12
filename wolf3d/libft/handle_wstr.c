/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 22:08:36 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 13:54:08 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

static int				calc_wstrlen(wchar_t *str, int precision, int i)
{
	if (*str == '\0' || precision == 0)
		return (i);
	else if (*str <= 0x7F)
		return (calc_wstrlen(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (calc_wstrlen(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (calc_wstrlen(str + 1, precision - 3, i + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (calc_wstrlen(str + 1, precision - 4, i + 4));
	else
		return (i);
}

int						handle_wstr(t_format form, va_list *list)
{
	wchar_t	*str;
	int		len;

	str = va_arg(*list, wchar_t *);
	if (str == NULL)
		str = (wchar_t *)L"(null)";
	len = (!(form.has_precision)) ? (int)ft_wstrlen(str) :
		calc_wstrlen(str, form.precision, 0);
	if (form.has_width && !form.flag['-'] && form.width > len)
		putchars(form.width - len, (char)(form.flag['0'] ? '0' : ' '));
	ft_putnwstr(str, (size_t)len);
	if (form.has_width && form.flag['-'] && form.width > len)
		print_spaces((size_t)form.width - len);
	return (form.width > len ? form.width : len);
}
