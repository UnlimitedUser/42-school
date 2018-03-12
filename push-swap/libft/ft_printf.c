/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 21:12:30 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/04 15:50:22 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

int		ft_init(const char *format, va_list *list, size_t nr)
{
	char	*arg;
	int		size;

	arg = ft_strchr(format, '%');
	if (!*format)
		return ((int)nr);
	else if (!arg)
	{
		ft_putstr(format);
		return ((int)nr + (int)ft_strlen(format));
	}
	else if (arg > format)
	{
		ft_putnstr(format, arg - format);
		return (ft_init(arg, list, nr + (arg - format)));
	}
	else
	{
		if ((size = process_arg(&format, list)) == -1)
			return (-1);
		else
			return (ft_init(format, list, nr + size));
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		list;
	int			res;

	if (!(format))
		return (0);
	va_start(list, format);
	res = ft_init(format, &list, 0);
	va_end(list);
	return (res);
}
