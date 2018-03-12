/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:02:30 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 12:07:59 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

void	pre_process(t_format form, int num_len, int len, char *pre)
{
	if (form.width > len && !form.flag['-'] && form.flag[' '] && form.flag['0'])
		putchars(1, ' ');
	if (form.width > len && !form.flag['-'])
		putchars(form.width - len, (char)((form.flag['0'] &&
						!form.has_precision) ? '0' : ' '));
	if (*pre && (form.precision < num_len || form.width > num_len) &&
			!form.flag['0'])
		ft_putchar(*pre);
	if (form.precision > num_len)
		putchars(form.precision - num_len, '0');
}

int		handle_int(t_format form, va_list *list)
{
	intmax_t	n;
	int			len;
	char		*pre;
	int			num_len;

	pre = "";
	n = extract_signed(&form, list);
	if (form.flag['+'] && n >= 0)
		pre = "+";
	else if (form.flag[' '] && n >= 0)
		pre = " ";
	else if (n < 0)
		pre = "-";
	len = calc_nbrlen_signed(n, 10, pre, &form);
	num_len = ft_numlen_base_signed(n, 10);
	if (((((form.flag['0']) || (form.precision > num_len && form.width <=
							num_len)))) && ((form.flag['+'] || n < 0)))
		ft_putchar(*pre);
	pre_process(form, num_len, len, pre);
	ft_putnstr(ft_intmax_ttoa(n) + ((n < 0) ? 1 : 0), (size_t)len);
	if (form.width > len && form.flag['-'])
		putchars(form.width - len, ' ');
	return ((form.width > len) ? form.width : len);
}
