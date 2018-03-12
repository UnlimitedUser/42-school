/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:22:02 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 13:54:51 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

#define A form.precision > (int)ft_strlen(str) ? ft_strlen(str) : form.precision

int		handle_str(t_format form, va_list *list)
{
	char	*str;
	int		len;

	if (form.length[0] == 'l')
		return (handle_wstr(form, list));
	str = va_arg(*list, char *);
	if (str == NULL)
		str = "(null)";
	len = (form.has_precision && form.precision >= 0) ? A : (int)ft_strlen(str);
	if (form.has_width && !form.flag['-'] && form.width > len)
		putchars(form.width - len, (char)(form.flag['0'] ? '0' : ' '));
	ft_putnstr(str, (size_t)len);
	if (form.has_width && form.flag['-'] && form.width > len)
		print_spaces((size_t)form.width - len);
	return (form.width > len ? form.width : len);
}
