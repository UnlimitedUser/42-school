/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 22:29:11 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 13:24:53 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

static void	rt_putchar(char a)
{
	write(1, &a, 1);
}

int			handle_char(t_format form, va_list *list)
{
	if (form.length[0] == 'l')
		return (handle_wchar(form, list));
	if (form.has_width && form.width > 1 && !form.flag['-'])
		putchars(form.width - 1, (char)(form.flag['0'] ? '0' : ' '));
	rt_putchar(va_arg(*list, int));
	if (form.has_width && form.width > 1 && form.flag['-'])
		print_spaces((size_t)form.width - 1);
	return (form.width > 1 ? form.width : 1);
}
