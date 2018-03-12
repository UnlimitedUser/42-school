/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_functions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:43:09 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/05 21:12:02 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_FUNCTIONS_H
# define INTERNAL_FUNCTIONS_H

# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# include <stdint.h>

typedef struct						s_format
{
	char							flag[255];
	unsigned int					has_width : 1;
	int								width;
	unsigned int					has_precision : 1;
	int								precision;
	char							length[3];
	char							specifier;
}									t_format;

typedef struct						s_print
{
	char							specifier;
	int								(*f)(t_format, va_list *);
}									t_print;

int									handle_str(t_format form, va_list *list);
int									process_arg(const char **format,
		va_list *list);
int									handle_wstr(t_format form, va_list *list);
int									handle_char(t_format form, va_list *list);
int									handle_wchar(t_format form, va_list *list);
int									handle_escape(t_format form, va_list *list);
int									handle_int(t_format form, va_list *list);
int									handle_unsigned(t_format form,
		va_list *list);
intmax_t							extract_signed(t_format *arg,
		va_list *args);
uintmax_t							extract_unsigned(t_format *arg,
		va_list *args);
int									handle_hex(t_format form, va_list *list);
int									handle_long(t_format form, va_list *list);
int									handle_ptr(t_format form, va_list *list);
int									handle_octal(t_format form, va_list *list);
int									handle_long_octal(t_format form,
		va_list *list);
int									handle_long_unsigned(t_format form,
		va_list *list);
int									ft_numlen_base_unsigned(uintmax_t nbr,
		int base);
int									ft_numlen_base_signed(intmax_t nbr,
		int base);
int									calc_nbrlen_unsigned(uintmax_t nbr,
		int base, char *p, t_format *arg);
int									calc_nbrlen_signed(intmax_t nbr, int base,
		char *p, t_format *arg);
void								putchars(int len, char a);
void								handle_width_1(const char **format,
		t_format *form, va_list *list);
void								handle_width_2(const char **format,
		t_format *form, va_list *list);
void								handle_precision_1(const char **format,
		t_format *form, va_list *list);
void								handle_precision_2(const char **format,
		t_format *form, va_list *list);
int									handle_unknown(const char **format,
		t_format *form, va_list *list);
void								skip_num(const char **format);

#endif
