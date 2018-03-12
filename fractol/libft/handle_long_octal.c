/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_long_octal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:09:37 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/04 15:51:00 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

int		handle_long_octal(t_format form, va_list *list)
{
	form.length[0] = 'l';
	return (handle_octal(form, list));
}
