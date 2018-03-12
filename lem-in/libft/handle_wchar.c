/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:54:40 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 13:52:36 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

int		handle_wchar(t_format form, va_list *list)
{
	wchar_t		chr;
	int			chr_len;

	chr = (wchar_t)va_arg(*list, int);
	chr_len = (int)ft_chrlen(chr);
	if (form.has_width && (form.width > chr_len) && !form.flag['-'])
		putchars(form.width - chr_len, (char)(form.flag['0'] ? '0' : ' '));
	ft_putchar(chr);
	if (form.has_width && (form.width > chr_len) && form.flag['-'])
		print_spaces((size_t)form.width - chr_len);
	return (form.width > chr_len ? form.width : (int)chr_len);
}
