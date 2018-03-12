/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:52:13 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 13:53:35 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

static void		put_hash(t_format form, char *str, int *hash)
{
	if (form.flag['#'] && form.specifier == 'x' && *str != '0')
		ft_putstr("0x");
	else if (form.flag['#'] && form.specifier == 'X' && *str != '0')
		ft_putstr("0X");
	*hash = 0;
}

static void		skip_zero(char **str, t_format form, int len)
{
	int		c;

	c = 0;
	while (str[c] && c < len && **str == '0' && c < form.precision - 1)
		c++;
	*str += c;
}

static void		print(char *str, t_format form, int len)
{
	if (len < form.precision)
		putchars(form.precision - len, '0');
	ft_putnstr(str, (size_t)str);
}

void			put_in_str(char **str, t_format form, va_list *list)
{
	if (form.specifier == 'x')
		*str = ft_uintmax_ttoa_base(extract_unsigned(&form, list), 16);
	else
		*str = ft_uintmax_ttoa_base_upper(extract_unsigned(&form, list), 16);
}

#define A ((len > form.precision) ? len : form.precision)

int				handle_hex(t_format form, va_list *list)
{
	char		*str;
	int			len;
	int			hash;

	hash = 1;
	put_in_str(&str, form, list);
	if (form.flag['0'] && form.flag['#'])
		put_hash(form, str, &hash);
	len = ((form.flag['#'] && *str != '0') ? (int)ft_strlen(str) + 2 :
			(int)ft_strlen(str));
	len = (form.has_precision && *str == '0') ? 0 : len;
	form.precision = (form.has_precision) ? A : len;
	if (form.has_width && !form.flag['-'] && form.width > form.precision)
		putchars(form.width - (size_t)form.precision,
				(char)(form.flag['0'] ? '0' : ' '));
	if (hash)
		put_hash(form, str, &hash);
	skip_zero(&str, form, len);
	if ((form.precision && form.has_precision) || (!form.has_precision))
		print(str, form, len);
	if (form.has_width && form.flag['-'] && form.width > form.precision)
		print_spaces((size_t)form.width - form.precision);
	return ((form.width > form.precision ? form.width : form.precision));
}
