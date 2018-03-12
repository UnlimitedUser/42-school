/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 16:57:19 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 13:54:26 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

int		handle_escape(t_format form, va_list *list)
{
	(void)list;
	if (form.has_width && form.width > 1 && !form.flag['-'])
		putchars(form.width - 1, (char)(form.flag['0'] ? '0' : ' '));
	ft_putchar('%');
	if (form.has_width && form.width > 1 && form.flag['-'])
		print_spaces((size_t)form.width - 1);
	return (form.width > 1 ? form.width : 1);
}
