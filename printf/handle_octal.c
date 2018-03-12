/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 22:31:35 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 13:53:08 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

static void	print(char *str, t_format form, int len)
{
	if (len < form.precision)
		putchars(form.precision - len, '0');
	if (form.flag['#'])
		ft_putchar('0');
	if (((form.precision && form.has_precision) || (!form.has_precision)) &&
			!(form.flag['#'] && *str == '0'))
		ft_putnstr(str, (size_t)str);
}

#define A ((len > form.precision) ? len : form.precision)
#define B (form.width > form.precision ? form.width : form.precision)

int			handle_octal(t_format form, va_list *list)
{
	char		*str;
	int			len;

	str = ft_uintmax_ttoa_base(extract_unsigned(&form, list), 8);
	len = ((form.flag['#'] && *str != '0') ? (int)ft_strlen(str) + 1 :
			(int)ft_strlen(str));
	len = (form.has_precision && *str == '0') ? 0 : len;
	form.precision = (form.has_precision) ? A : len;
	if (form.has_width && !form.flag['-'] && form.width > form.precision)
		putchars(form.width - form.precision,
				(char)(form.flag['0'] ? '0' : ' '));
	print(str, form, len);
	if (form.has_width && form.flag['-'] && form.width > form.precision)
		print_spaces((size_t)form.width - form.precision);
	return ((form.flag['#'] && *str == '0') ? 1 : B);
}
