/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 12:18:33 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 12:49:56 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

void	handle_width_1(const char **format, t_format *form, va_list *list)
{
	(void)format;
	form->has_width = 1;
	form->width = va_arg(*list, int);
	if (form->width < 0)
	{
		form->flag['-'] = 1;
		form->width *= -1;
	}
}

void	handle_width_2(const char **format, t_format *form, va_list *list)
{
	(void)list;
	form->has_width = 1;
	form->width = ft_atoi(*format);
	skip_num(format);
}

void	handle_precision_1(const char **format, t_format *form, va_list *list)
{
	form->has_precision = 1;
	form->precision = va_arg(*list, int);
	if (form->precision < 0)
		form->has_precision = 0;
	(*format)++;
}

void	handle_precision_2(const char **format, t_format *form, va_list *list)
{
	(void)list;
	form->has_precision = 1;
	(*format)++;
	form->precision = 0;
	form->precision = ft_atoi(*format);
	skip_num(format);
}

int		handle_unknown(const char **format, t_format *form, va_list *list)
{
	(void)list;
	if (!form->flag['-'] && form->width > 1)
		putchars(form->width - 1, (char)((form->flag['0']) ? '0' : ' '));
	ft_putchar(**format);
	if (form->flag['-'] && form->width > 1)
		putchars(form->width - 1, (char)((form->flag['0']) ? '0' : ' '));
	(*format)++;
	return (1);
}
