/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_long_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:14:31 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 12:02:57 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

int		handle_long_unsigned(t_format form, va_list *list)
{
	form.length[0] = 'l';
	return (handle_unsigned(form, list));
}
