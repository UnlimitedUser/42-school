/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:08:42 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 12:17:27 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

t_print								g_printf_funcs[15] = {
	{
		.specifier = 's',
		.f = &handle_str
	},
	{
		.specifier = 'S',
		.f = &handle_wstr
	},
	{
		.specifier = 'c',
		.f = &handle_char
	},
	{
		.specifier = 'C',
		.f = &handle_wchar
	},
	{
		.specifier = '%',
		.f = &handle_escape
	},
	{
		.specifier = 'i',
		.f = &handle_int
	},
	{
		.specifier = 'd',
		.f = &handle_int
	},
	{
		.specifier = 'u',
		.f = &handle_unsigned
	},
	{
		.specifier = 'x',
		.f = &handle_hex
	},
	{
		.specifier = 'X',
		.f = &handle_hex
	},
	{
		.specifier = 'D',
		.f = &handle_long
	},
	{
		.specifier = 'p',
		.f = &handle_ptr
	},
	{
		.specifier = 'U',
		.f = &handle_long_unsigned
	},
	{
		.specifier = 'O',
		.f = &handle_long_octal
	},
	{
		.specifier = 'o',
		.f = &handle_octal
	}
};

int		put_length(const char **format, t_format *form)
{
	if ((*(*format) == 'h' && *((*format) + 1) == 'h') ||
			(*(*format) == 'l' && *((*format) + 1) == 'l'))
	{
		form->length[0] = *(*format);
		form->length[1] = *((*format) + 1);
		(*format)++;
		return (1);
	}
	else if (*(*format) == 'h' || *(*format) == 'l' ||
			*(*format) == 'j' || *(*format) == 'z')
	{
		form->length[0] = *(*format);
		return (1);
	}
	return (0);
}

int		arg_type(const char **format, t_format *form, va_list *list)
{
	if (*(*format) == '-' || *(*format) == '+'
			|| *(*format) == ' ' || *(*format) == '#' || *(*format) == '0')
		form->flag[(int)(*(*format))] = 1;
	else if (*(*format) == '*')
		handle_width_1(format, form, list);
	else if (ft_isdigit(*(*format)))
		handle_width_2(format, form, list);
	else if (*(*format) == '.' && *((*format) + sizeof(char)) == '*')
		handle_precision_1(format, form, list);
	else if (*(*format) == '.')
		handle_precision_2(format, form, list);
	else if (put_length(format, form))
		;
	else if (ft_strchr("sSpdDioOuUxXcC%", **format))
	{
		form->specifier = *(*format);
		(*format)++;
		return (1);
	}
	else
		return (handle_unknown(format, form, list));
	return (0);
}

int		process_arg(const char **format, va_list *list)
{
	t_format	form;
	int			c;

	c = -1;
	form.has_precision = 0;
	form.has_width = 0;
	form.precision = 0;
	form.width = 0;
	ft_memset(form.length, '\0', 3);
	form.flag['0'] = 0;
	form.flag['#'] = 0;
	form.flag[' '] = 0;
	form.flag['-'] = 0;
	form.flag['+'] = 0;
	if (!(*++(*format)))
		return (0);
	while ((*(*format)) && !arg_type(format, &form, list))
		(*format)++;
	while (++c < 15)
		if (g_printf_funcs[c].specifier == form.specifier)
			return (g_printf_funcs[c].f(form, list));
	return (MAX(form.width, 1));
}
